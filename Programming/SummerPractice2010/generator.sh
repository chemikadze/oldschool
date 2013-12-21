while read x && read y; do echo "Image1.Canvas.LineTo(Round((Image1.Width-20)/8 * $x +10), Image1.Height - Round((Image1.Height-20)/8 * $y ) - 10);"; done
