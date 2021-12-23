import unittest

import utils


class TestUtils(unittest.TestCase):
    def test_esprimo(self):
        self.assertFalse(utils.esprimo(4))
        self.assertTrue(utils.esprimo(2))
        self.assertTrue(utils.esprimo(3))
        self.assertFalse(utils.esprimo(8))
        self.assertFalse(utils.esprimo(10))
        self.assertTrue(utils.esprimo(7))
        self.assertEqual(utils.esprimo(-3),
                         "numeros negativos no son permitidos")


if __name__ == '__main__':
    unittest.main()
