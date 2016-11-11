#lang r5rs
(define x (list 'a 'b))
(define z1 (cons x x))
(define (count-pairs x)
  (if (not (pair? x))
      0
      (+ (count-pairs (car x))
         (count-pairs (cdr x))
         1)))
(count-pairs z1)

(define z2 (cons z1 x))

(define (count-pairs-improved x)
  (cond ((not (pair? x)) 0)
        ((eq? (car x) (cdr x)) (+ (count-pairs-improved (car x)) 1))
        (else (+ (count-pairs-improved (car x))
                 (count-pairs-improved (cdr x))
                 1))))

(define (count-pairs2 x)
  (cond ((not (pair? x)) 0)
        (else (memq (car x) (cdr x)))))

(define (last-pair lst)
    ( cond ((null? lst) lst)
           ((null? (cdr lst)) lst)
           (else (last-pair (cdr lst)))))
(define (make-cycle x)
	(set-cdr! (last-pair x) x)
 x)
(define z (make-cycle (list 'a 'b 'c)))

(define (cyclic? lst)
  (let ((x 1))

    ))
