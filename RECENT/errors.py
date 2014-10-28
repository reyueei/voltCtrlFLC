class E_VolColProcessException(Exception):
	def __init__(self, p_error_code, p_error_msg):
		self._m_error_code = p_error_code
		self._m_error_msg = p_error_msg

	def getErrorCode(self):
		return self._m_error_code

	def getErrorMsg(self):
		return self._m_error_msg

class E_NoProcesses(E_VolColProcessException):
	def __init__(self, p_error_msg = None):
		super(E_NoProcesses, self).__init__(00, p_error_msg)
		if not p_error_msg:
			self._m_error_msg = "No processes."

class E_NoValue(E_VolColProcessException):
	def __init__(self, p_error_msg = None):
		super(E_NoValue, self).__init__(01, p_error_msg)
		if not p_error_msg:
			self._m_error_msg = "No stored value."
