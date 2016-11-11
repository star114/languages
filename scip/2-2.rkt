#lang racket
;(define input (list (list 1 (list 2 3)) (list 4 5)))
;(define input2 (list (list 1 (list 2 (list 3 6))) (list 4 (list (list 5 9) (list 7 8)))))

(define deep-reverse
  (lambda (x)
    (define deep-reverse-inner
      (lambda (in out)
        (cond [(empty? in) out]
              [else (deep-reverse-inner (cdr in) (cons (deep-reverse (car in)) out ))]
        )
      )
    )
    ;(display x)
    ;(newline)
    (cond [(not (list? x)) x]
          [else (deep-reverse-inner x empty)])
    )
  )
;(deep-reverse input)
;(deep-reverse input2)