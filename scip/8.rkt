#lang racket
;; Rectangular expression
(define (real-part-rect z) (car z))
(define (imag-part-rect z) (cdr z))
(define (magnitude-rect z) (sqrt (+ (* (real-part-rect z) (real-part-rect z)) (* (imag-part-rect z) (imag-part-rect z)))))
(define (angle-rect z) (atan (/ (imag-part-rect z) (real-part-rect z))))
(define (make-from-real-imag-rect x y) (cons x y))
(define (make-from-mag-ang-rect r a) (cons (* r (cos a)) (* r (sin a))))

(define rec-com (cons 3 4))

;; Polar expression
(define (magnitude-polar z) (car z))
(define (angle-polar z) (cdr z))
(define (real-part-polar z) (* (magnitude-polar z) (cos (angle-polar z))))
(define (imag-part-polar z) (* (magnitude-polar z) (sin (angle-polar z))))
(define (make-from-real-imag-polar x y) (cons (sqrt (+ (* x x) (* y y))) (atan (/ y x))))
(define (make-from-mag-ang-polar r a) (cons r a))

(define pol-com (cons 5 0.9272952180016122))

;; Adding tags to data
(define (attach-tag type-tag contents)
  (cons type-tag contents))
(define (type-tag datum)
  (if (pair? datum)
      (car datum)
      (error "Bad tagged datum -- TYPE-TAG" datum)))
(define (contents datum)
  (if (pair? datum)
      (cdr datum)
      (error "Bad tagged datum -- CONTENTS" datum)))

;; Check tags
(define (rectangular? z)
  (eq? (type-tag z) 'rectangular))
(define (polar? z)
  (eq? (type-tag z) 'polar))

(define (real-part z)
  (cond ((rectangular? z) (real-part-rect (contents z)))
        ((polar? z) (real-part-polar (contents z)))
        (else error "Bad type" z)
        )
  )
(define (imag-part z)
  (cond ((rectangular? z) (imag-part-rect (contents z)))
        ((polar? z) (imag-part-polar (contents z)))
        (else error "Bad type" z)
        )
  )
(define (magnitude z)
  (cond ((rectangular? z) (magnitude-rect (contents z)))
        ((polar? z) (magnitude-polar (contents z)))
        (else error "Bad type" z)
        )
  )
(define (angle z)
  (cond ((rectangular? z) (angle-rect (contents z)))
        ((polar? z) (angle-polar (contents z)))
        (else error "Bad type" z)
        )
  )
(define (make-from-real-imag x y)
  (attach-tag 'rectangular (cons x y))
  )
(define (make-from-mag-ang r a)
  (attach-tag 'polar (cons r a))
  )
  
  

(define rec-com-tag (attach-tag 'rectangular rec-com))
(define pol-com-tag (attach-tag 'polar pol-com))
;;complex number arithmatics
(make-from-real-imag (real-part rec-com-tag) (imag-part rec-com-tag))
(make-from-mag-ang (magnitude rec-com-tag) (angle rec-com-tag))
(make-from-real-imag (real-part pol-com-tag) (imag-part pol-com-tag))
(make-from-mag-ang (magnitude pol-com-tag) (angle pol-com-tag))

(define (add-complex z1 z2)
  (make-from-real-imag ( + (real-part z1) (real-part z2))
                       ( + (imag-part z1) (imag-part z2))))
(define (sub-complex z1 z2)
  (make-from-real-imag (- (real-part z1) (real-part z2))
                       (- (imag-part z1) (imag-part z2))))
(define (mul-complex z1 z2)
  (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                     (+ (angle z1) (angle z2))))
(define (div-complex z1 z2)
  (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                     (- (angle z1) (angle z2))))