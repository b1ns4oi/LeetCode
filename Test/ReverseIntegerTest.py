import unittest

from ..Code.ReverseInteger import Solution

class ReverseIntegerTest(unittest.TestCase):
	def test_reverse_integer(self):
 		s = Solution()
 		self.assertEqual(0, s.reverse(0))
 		self.assertEqual(1, s.reverse(1))
 		self.assertEqual(1, s.reverse(10))
 		self.assertEqual(1, s.reverse(100))
 		self.assertEqual(123, s.reverse(321))
 		self.assertEqual(1000001, s.reverse(1000001))
 		self.assertEqual(12345678, s.reverse(87654321))
