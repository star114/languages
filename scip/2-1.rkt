#lang racket
;(define input (list (list 1 (list 2 3)) (list 4 5)))
;(define input2 (list (list 1 (list 2 (list 3 6))) (list 4 (list (list 5 9) (list 7 8)))))
(define flatten
  (lambda (x)
    (cond [(empty? x) null]
          [(not (list? x)) (cons x '())]
          [else (append (flatten (car x)) (flatten (cdr x)))]
          )))
;(flatten input)
;(flatten input2)