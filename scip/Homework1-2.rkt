#lang racket
; homework 2
(define (new-empty-list) '())
(define (list-empty? x) (equal? x '()))
(define (list-length x)
  (if (list-empty? x) 0 (+ 1 (list-length (car x))))
  )
(define (list-insert x y) (cons x y))
(define (list-get x n)
  (cond
    [(or (< n 0) (<= (list-length x) n)) (error "incorrect index number")]
    [(equal? (list-length x) (+ n 1)) (cdr x)]
    [else (list-get (car x) n)]
    )
  )

; test
;(define l (new-empty-list))
;(define ll (list-insert l "hello"))
;(define lll (list-insert ll "from"))
;