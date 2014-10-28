import voltage_collector as vc
import voltage_processor as vp
import errors as err

try:
	processor = vp.VoltageProcessor()

	threads = []

	vc1 = vc.VoltageCollector(0, 'uart4', '/dev/ttyS4')
	vc2 = vc.VoltageCollector(1, 'uart3', '/dev/ttyS3')
	vc3 = vc.VoltageCollector(2, 'uart7', '/dev/ttyS6')

	vc1.start()
	vc2.start()
	vc3.start()

	processor.addVolCol(vc1)
	processor.addVolCol(vc2)
	processor.addVolCol(vc3)

	processor.start()
	
	threads.append(processor)
	threads.append(vc1)
	threads.append(vc2)
	threads.append(vc3)

	for t in threads:
		t.join()

except (err.E_NoProcesses) as e:
	processor.closeProcessor()
except (Exception) as e:
	print ('STD Error: ' + str(e))
	processor.closeProcessor()
