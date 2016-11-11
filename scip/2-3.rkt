#lang racket
(define subsets
  (lambda (s)
    (if (empty? s) (list empty)
        (let ((rest (subsets (cdr s))))
          (append rest (map (lambda (x) (cons (car s) x)) rest))))))

(subsets (list 1 2 3))
