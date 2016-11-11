#lang racket

(define make-vect cons)
(define add-vect (lambda (x y) (make-vect (+ (car x) (car y)) (+ (cdr x) (cdr y)))))
(define sub-vect (lambda (x y) (make-vect (- (car x) (car y)) (- (cdr x) (cdr y)))))
(define scale-vect (lambda (c x) (make-vect (* c (car x)) (* c (cdr x)))))
(define xcor-vect car)
(define ycor-vect cdr)
(define make-frame list)
(define origin-frame car)
(define edge1-frame cadr)
(define edge2-frame caddr)

(define (frame-coord-map frame)
  (lambda (v)
    (add-vect
     (origin-frame frame)
     (add-vect (scale-vect (xcor-vect v) (edge1-frame frame))
               (scale-vect (ycor-vect v) (edge2-frame frame))
               )
     )
    )
  )

;(define test-frame0 (make-frame (make-vect 0 0) (make-vect 100 0) (make-vect 0 100)))
;(define test-frame1 (make-frame (make-vect 100 100) (make-vect 100 100) (make-vect -100 100)))
;((frame-coord-map test-frame0) (make-vect 1 1))
;((frame-coord-map test-frame1) (make-vect 1 1))

(require racket/gui/base)

(define picture-size 300)

(define bitmap
  (make-object bitmap% (+ picture-size 1) (+ picture-size 1)))

(define bitmap-dc
  (new bitmap-dc% [bitmap bitmap]))

(define frame
  (new frame% [label "SICP Picture Language"]))

(define canvas
  (new canvas%
     [parent frame]
     [min-width (+ picture-size 1)]
     [min-height (+ picture-size 1)]
     [paint-callback (lambda (canvas dc)
                       (send dc draw-bitmap bitmap 0 0))]))

(define (draw-line start end)
  (send bitmap-dc 
        draw-line
        (xcor-vect start)
        (ycor-vect start)
        (xcor-vect end)
        (ycor-vect end)))

(define (erase-frame) (send bitmap-dc erase))

(define window (make-frame (make-vect 0 picture-size)
                           (make-vect picture-size 0)
                           (make-vect 0 (- 0 picture-size))))

(define make-segment list)
(define start-segment car)
(define end-segment cadr)

;(define temp-segment-list
;  (list (make-segment (make-vect 0 3) (make-vect 1 0.3))
;        (make-segment (make-vect 0.2 0) (make-vect 0.2 1))))

(define (simple-segments->painter segment-list)
  (for-each (lambda (x) (draw-line (start-segment x) (end-segment x))) segment-list))

;(simple-segments->painter (list (make-segment (make-vect 0 0) (make-vect picture-size picture-size))
;       (make-segment (make-vect picture-size 0) (make-vect 0 picture-size)))) 
; (send frame show #t)

(define(segments->painter segment-list)
    (lambda (frame)
      (for-each
       (lambda (segment)
         (draw-line
          ((frame-coord-map frame) (start-segment segment))
          ((frame-coord-map frame) (end-segment segment))
          ))
       segment-list)))




;(define (new-painter segment-list)
;  ((segments->painter (map (lambda (x) (make-segment (scale-vect (/ 1 3) (start-segment x)) (scale-vect (/ 1 3) (end-segment x)))) segment-list)) window)
;)


(define window-frame (make-frame (make-vect 0 picture-size)
                           (make-vect 100 0)
                           (make-vect 0 (- 0 100))))

(define (new-painter segment-list)
  ((segments->painter segment-list) window-frame)
)

(define temp-segment-list
  (list (make-segment (make-vect 0 1) (make-vect 3 1))
        (make-segment (make-vect 1 0) (make-vect 1 3))
         (make-segment (make-vect 0 0) (make-vect 3 3))
        ))

(new-painter temp-segment-list) 
 (send frame show #t)