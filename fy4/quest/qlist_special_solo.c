/*	fy2005 introduces two new qlist
	Special Quest: qlist_special �� Repeatable Quest: qlist_repeat
	
	Qlist_repeat ��Ҫ��
	��1��ÿ��quest�����б仯��������Ӧһ����ͬ����Σ�
	��2���������㹻��NPC֧�ֶ��ˣ�
	��3�����Լ������˲����ᷳ
	
	Qlist_special��Ҫ��
	��1������Quest������questd�б�����̫��
	��2����һ���ĵ������ã�������һ��Ȥζ�Ե�����
	��3�������ǲ���ô�ɾ�û�˻�������ע��Ķ���
	
*/	

#include <ansi.h>
inherit SKILL;

mapping *quest = ({
	  
	([											// Ŀ�ģ� Let ppl know where to cure ����
		"quest":	"����ҽ��",
		"long":		"�������˵�����Ƴ��ϵ�÷��������һλ��ҽ������ȥ̽̽����ס������˵��
���ڻ������������Ժ���������Ĵ���ǡ���������ҽƢ���Ź֣�û��û��ǧ
��Ҫȥ��������",
		"short":	"�����Ƴ��ϵ�÷����ȥ�ݷ���ҽ",
		"owner":	"mei da",		
		"location":	"���Ƴ���",		
		"duration":		600,			
		"cancel": 		-1,					
		"exp_l":		2,						
		"exp_h":		50,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ� improve unarmed
		"quest":	"��ʨʯ��",
		"long":		"�������˵����ı���̫��������ʨ�ھֵ����䳡��ȥ����������",
		"short":	"����ʨ�ھֵ����䳡��ȥ��ʮ��ʯ��",
		"owner":	"meng",		
		"location":	"���Ƴ�",		
		"duration":		600,				
		"cancel": 		-1,					
		"exp_l":		2,						
		"exp_h":		20,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ� improve move 
		"quest":	"��ʨ÷��׮",
		"long":		"�������˵�������̫��������ʨ�ھֵ����䳡��ȥ����������",
		"short":	"����ʨ�ھֵ����䳡��ȥ��ʮȦ÷��׮",
		"owner":	"meng",		
		"location":	"���Ƴ�",		
		"duration":		600,			
		"cancel": 		-1,					
		"exp_l":		3,						
		"exp_h":		20,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�teach "listen"
		"quest":		"��ѩ����",
		"long":			"������˵�����������һ�����ɾ��£���Ϊ��ѩ˫�������֪�������ںδ���",
		"short":		"�ҵ���ѩ����",
		"owner":		"none",				
		"location":		"��ѩɽׯ",			
		"duration":		600,	
		"cancel": 		-1,				
		"difficulty":	0,				
		"exp_l":		2,				
		"exp_h":		30,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle and books
		"quest":		"�䵱�ͷ�",
		"long":			"������˵����䵱С���ϵ��ϸ���ȱ��"WHT"�ͷ�"CYN"����ȥ���æ�ɡ�",
		"short":		"���䵱С���ϵ��ϸ����ͷ�",
		"owner":		"old woman",				
		"location":		"�䵱ɽ��",			
		"duration":		600,	
		"difficulty":	0,				
		"exp_l":		2,				
		"exp_h":		30,			
		"quest_type":	"special",		
	]),	
	([
		"quest":	"�����ӶĲ�",				// Ŀ�ģ�FY feature
		"long":		"�������˵������ȥ�����ĳ�����ˣ����������үүȥӮ�ص���������",
		"short":	"�������ĳ�ʤһȦ����",
		"owner":	"huang",		
		"location":	"���Ƴ�",		
		"duration":		1800,			
		"difficulty":	100,			
		"cancel": 		-1,
		"exp_l":		3,						
		"exp_h":		50,					
		"quest_type":	"special",		
	 ]),
/*	([											// Ŀ�ģ����literate
		"quest":	"��ʫ",
		"long":		"�㳡�����ǵ�һ��С¥���Ȼ����۵ر������ʣ��������Ц��˵��������ʫ\n"
				"���½����˸���ʫ���ӡ�����ţ���ȥ�����Զ�ʫ�ɣ�Ҳ��Ҫ�����ѧ�书��",
				//	��������ڽ�������ʱ��˵�Ļ�
		"short":	"������Ŵ�ȥ�Գ������ʫ",	// ����player��quest�����ѯʱ������
		"owner":	"suan xiucai",				// quest�ĸ����ߣ�
		"location":	"����ʫ��",					// �ص�
		"cancel": 		100,	// cancel +100%.
		"duration":		1800,					// ʱ��
		"difficulty":	200,					// �Ѷȣ�����difficulty/100����
		"exp_l":		3,						// Quest ��ʼ�����
		"exp_h":		100,					// Quest ���������	
		"quest_type":	"special",				// ���ͣ������ƺ�û�ã�
	]),*/		
	([											// Ŀ�ģ�FY feature
		"quest":	"��ʮ�ĵ�",
		"long":		"�������˵������˽��ѧ�õ��������ڳ������أ�ȥ���Կ���",
		"short":	"��˽�������Ƕ�ȥ�����������",
		"owner":	"sishu",		
		"location":	"���Ƴ�",		
		"duration":	900,	
		"cancel": 		-1,			
		"difficulty":	200,			
		"exp_l":		3,						
		"exp_h":		100,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ� improve move (60-75)
		"quest":	"��ƽ÷��׮",
		"long":		"�������˵����������ǲ��У�����ƽɽׯ�����䳡��ȥ����������",
		"short":	"����ƽɽׯ�����䳡��ȥ��ʮȦ÷��׮",
		"owner":	"meng",		
		"location":	"��ƽɽׯ",		
		"duration":	600,			
		"cancel": 		-1,					
		"exp_l":		10,						
		"exp_h":		30,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ� a chance to get salt
		"quest":	"�½�װ��",
		"long":		"�������˵���½��������γ���ȱ�˸ɻ��ȥ׬���㻨Ǯ�ɡ�",
		"short":	"���½��������γ�����ɻ�",
		"owner":	"saltboss",		
		"location":	"�½�",		
		"duration":		900,			
		"difficulty":	0,		
		"cancel": 		-1,					
		"exp_l":		10,						
		"exp_h":		30,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ� teach riddle-solving
		"quest":	"��������",
		"long":		"�������˵�����ƳǱ����������˵�и������ӣ�����ȥ̽�������������ֻ�
�����ػ��˶�Ŀ����ס����Ҫ�����࿴����ȫ����ˡ�",
		"short":	"�����ƳǱ���������ȥ������ʲô����",
		"owner":	"none",		
		"location":	"���Ƴ���",		
		"duration":		600,			
		"cancel": 		-1,					
		"exp_l":		10,						
		"exp_h":		50,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�riddle
		"quest":		"�����Ӱ",
		"long":			"������˵��������Ѧ���������ʵ�����ȥ�����ܲ���"YEL"ʩ��"CYN"��Щʲô��",
		"short":		"�����Ƴ����Ѧ��������ȥ���������",
		"owner":		"none",				
		"location":		"���Ƴ�",	
		"duration":		900,			
		"difficulty":	0,	
		"cancel": 		0,				
		"exp_l":		40,				
		"exp_h":		70,			
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�riddle
		"quest":		"������ʤ",
		"long":			"������˵��������Ϻ����˼�С��ȥ����ʤ�ذ��Ƶ��ĺ������¿�ʼӪ���ˣ�
ֻ��ϧ�����Ϸ�ʵ�ڳ鲻������ȥ����ȥ����ת��һת�ɡ�",
		"short":		"�����Ƴ�ȥ���",
		"owner":		"none",				
		"location":		"����",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	0,				
		"exp_l":		30,				
		"exp_h":		100,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ��: riddle			
		"quest":	"�䵱��",
		"long":		"�������˵���䵱ɽ��С�����и�Сϱ����������"YEL"����"CYN"����ȥ������ɡ�",
		"short":	"���䵱ɽ��С���Сϱ��������",
		"owner":	"dahan",		
		"location":	"�䵱ɽ",		
		"duration":	900,			
		"cancel": 		100,			
		"difficulty":	100,			
		"exp_l":		40,						
		"exp_h":		70,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�riddle
		"quest":	"����ͭ��",
		"long":		"������˳�˼�����˴��˹����»������أ�����һͭ����������ͨ����
�����ȥ���飬�����������̻ر���",
		"short":	"���˹����£�������ͭ��",
		"owner":	"none",				
		"location":	"�˹�����",			
		"cancel": 		-1,			
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		50,				
		"exp_h":		60,			
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�My funny BIG mouse, and riddle solving
		"quest":	"��ʨ���",
		"long":		"�������˵����ʨ�ھֵĴ����Ҫ��"YEL"��æ"CYN"����ȥĥ��ĥ������ס��Ҫ�����ġ�",
		"short":	"����ʨ�ھֵĴ���Ƕ���æ",
		"owner":	"huang",		
		"location":	"���Ƴ�",		
		"cancel": 	-1,	// Cant cancel.
		"duration":		600,			
		"difficulty":	200,			
		"cancel": 		0,			
		"exp_l":		30,						
		"exp_h":		100,					
		"quest_type":	"special",		
	]),
	([											// Ŀ��: riddle
		"quest":	"�䵱��ˮţ",
		"long":		"�������˵���䵱ɽ�µķ�ţ�޵�ţ���ˣ���ȥ�������ΰɡ�",
		"short":	"���䵱ɽ�µķ�ţ���ҳ�ţ������ԭ��",
		"owner":	"little farmer",		
		"location":	"�䵱ɽ",		
		"duration":	900,			
		"cancel": 		-1,			
		"difficulty":	100,			
		"exp_l":		75,						
		"exp_h":		120,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�riddle
		"quest":	"�����¶���",
		"long":		"������˼��е������յ��¶������Ÿ룬���������ڹ���ԭʼɭ���У�
������ǰȥ��һ��֮����",
		"short":	"������ɭ�ְ����¶�������",
		"owner":	"none",				
		"location":	"����",			
		"duration":		900,			
		"difficulty":	0,
		"cancel": 		-1,							
		"exp_l":		80,				
		"exp_h":		120,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":	"���ɾ���",
		"long":		"������˼��������ƶ������������������ɽ��ͽ����ɽ�ٲ���������
����ȥ̽�������������������輫��������",
		"short":	"���ɾ���",
		"owner":	"none",				
		"location":	"���ɱ�",			
		"duration":		900,		
		"cancel": 		-1,				
		"difficulty":	100,				
		"exp_l":		80,				
		"exp_h":		120,			
		"quest_type":	"special",		
	]),		
		([											// Ŀ�ģ�riddle
		"quest":		"̽���˹�",
		"long":			"������˶���˵�������˹ȣ��������¶��˾ۼ�֮�ء���Щ��
û��һ������ʮ���⡢����Ѫ�ȡ��������˺�֮�ˣ����������˾���һ��Ҳû����
���߽����˹�һ����������ȷ�ȥΪ������̽��һ̽��",
		"short":		"̽�����˹���ʵ",
		"owner":		"none",				
		"location":		"���˹�",
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	0,				
		"exp_l":		100,				
		"exp_h":		150,			
		"quest_type":	"special",		
	]),			
	([											// Ŀ�ģ�riddle
		"quest":	"����ϲ��",
		"long":		"�������Ц��������ɽ����ɽׯԬ���ƵĶ��ӽ���Ȣ�ף�����ȥ�մ����ְɡ�",
		"short":	"�������ɽׯ��ϲ����",
		"owner":	"none",				
		"location":	"����ɽ",			
		"duration":		900,			
		"difficulty":	0,
		"cancel": 		-1,							
		"exp_l":		100,				
		"exp_h":		200,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ��: riddle
		"quest":		"�ɰ�����",
		"long":			"�������˵����˵������ĵ��鲹Ѫ����Զ�����������ܲ���ȥѧ��һ����",
		"short":		"��һ�ݵ��鲹Ѫ����",
		"owner":		"medman",		
		"location":		"������",		
		"duration":		900,			
		"cancel": 		-1,			
		"difficulty":	100,			
		"exp_l":		100,						
		"exp_h":		300,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�riddle
		"quest":	"�ɹ���ʯ",
		"long":		"������˵������ƶ�����ɽ���и��ط��е����ȣ���˵�������أ��־�
˵�����д���ֵĵط��а�ʯ�������ȥ�쿴�쿴��",
		"short":	"�������Ȱ�ʯ���쿴",
		"owner":	"none",				
		"location":	"������",			
		"duration":		900,			
		"cancel": 		1,			
		"difficulty":	0,				
		"exp_l":		200,				
		"exp_h":		450,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":		"�����Թ�",
		"long":			"������˵�������������������Ѫ�����ź�ҹ�۸��Ӻʹ������е�һλ�г��㺺
��ǰ��Զ�κ��⡣���ս�������ҹ�����ڳ������Թ�֮�󣬲�֪��α����ȥ������̽̽��ʵ�ɡ�
����֮����ֻҪ�����ڣ��ҵ�����Ȼ������ȥ��������",
		"short":		"�߹��������ĵ����Թ�����ҹ��",
		"owner":		"none",				
		"location":		"������",			
		"duration":		900,			
		"difficulty":	100,			
		"cancel": 		-1,				
		"exp_l":		200,				
		"exp_h":		600,			
		"quest_type":	"special",		
	]),									
	([											// Ŀ�ģ�riddle
		"quest":	"�������",
		"long":		"������������������ħ�������ۼ���̩ɽ�����ͼ�����������
���������У�̽������ʵ�������ر���",
		"short":	"�����̽����",
		"owner":	"none",				
		"location":	"���",			
		"duration":		1200,			
		"difficulty":	100,			
		"cancel": 		-1,				
		"exp_l":		300,				
		"exp_h":		350,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":	"��ˮ̽��",
		"long":		"������˵�����˵��ƽ���Ͱ�����������ˮ���У���֪������ʵ����
����ȥ̽��������",
		"short":	"�跨������ˮ��",
		"owner":	"none",				
		"location":	"��ˮ",			
		"duration":		900,			
		"difficulty":	100,
		"cancel": 		-1,							
		"exp_l":		300,				
		"exp_h":		350,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":		"ǧ�𰵲�",
		"long":			"���������ü���������ǧ��¥������ƽ��ȴ�ǲع�����֮�أ�����¥��
˽�谵�Σ�����Ϊ潣�����ȥ���������
������˿��˿���˵��ƾ���������ӣ����»��������Ƕ��֣���ס��
�򲻹������ܡ�",
		"short":		"̽��ǧ��¥�ĵ�ϸ",
		"owner":		"none",				
		"location":		"ǧ��¥",
		"cancel": 		-1,						
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		400,				
		"exp_h":		450,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":		"�´�����",
		"long":			"���������ü������˵�ڶ�������һ���ȳ����������غ�а��ĵط��������𵺣�
֮ǰ��ȥ��̽�ӣ�û�м������Ż����ģ�ƾ��������ӣ�����Ҳ������ֻ��������ֶ�ȱ��
���Ҵ��Ϸ�ǰȥ̽��һ̽���������뵺�У�ֻ������·�߾��С�",
		"short":		"�´�����",
		"owner":		"none",				
		"location":		"��������̽�����ϵ���ʵ",			
		"duration":		900,			
		"difficulty":	200,				
		"cancel": 		-1,			
		"exp_l":		450,				
		"exp_h":		530,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":		"̽����կ",
		"long":			"���������ü����̩ɽ����կ��ͽ������ɽ���٣�������ȥ̽����ʵ�źã�
������˿��˿���˵��ƾ���������ӣ����»��������Ƕ��֣���ס��
�򲻹������ܡ�����ס������ɽׯ��ȥ�ø����Ŷ��",
		"short":		"̽������կ��ʵ",
		"owner":		"none",				
		"location":		"̩ɽ",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	200,				
		"exp_l":		500,				
		"exp_h":		750,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":		"̽������",
		"long":			"���������ü���������ڷ�ͽ������ɽ���٣�������ȥ̽����ʵ�źã�
������˿��˿���˵��ƾ���������ӣ����»��������Ƕ��֣���ס��
Ҫ���ǲ�������",
		"short":		"̽����������ʵ",
		"owner":		"none",				
		"location":		"������",
		"cancel": 		-1,						
		"duration":		900,			
		"difficulty":	0,				
		"exp_l":		500,				
		"exp_h":		700,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ��: riddle
		"quest":		"��������",
		"long":			"�������˵���߳Ǹϳ��ձ����ϱ����Ȼ�����ز�����ȥ����취�ɡ�",
		"short":		"���ձ����ϱ���β�",
		"owner":		"sickman",		
		"location":		"�߳�",		
		"duration":		1200,					
		"difficulty":	100,			
		"exp_l":		500,						
		"exp_h":		1500,					
		"quest_type":	"special",		
	]),
	([											// Ŀ��: learn how to use "answer", learn �߳�����
		"quest":		"�����ƺ�",
		"long":			"�������˵����֪���߳Ǵ�Ũ������ô����̫�����ˣ���ȥ������ɣ�
�����û��˵������ôȥ���ʱ��ˣ��ú��������̶��㽫�����մ��а�����",
		"short":		"�����߳ǵĴ�Ũ",
		"owner":		"cuinong",		
		"location":		"�߳�",		
		"difficulty":	100,	
		"duration":		1200,				
		"exp_l":		500,						
		"exp_h":		1500,					
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":	"��½С��",
		"long":		"������˵���ħ�̵�����÷�����������������ת�ƣ�������üë��½
С�粻֪��ȥ��������ȥ�����ҵ���",
		"short":	"����÷ɽׯ�ҵ�½С��",
		"owner":	"none",				
		"location":	"��÷ɽׯ",			
		"cancel": 		-1,			
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		600,				
		"exp_h":		650,			
		"quest_type":	"special",		
	]),		
	([	
		"quest":	"��̽ˮ��",
		"long":		"�������˵��ü��۵�½�ϰ���Ϊ���Ĳ�ˮˮ�ʷ����ȥ�����ɡ�",
		"short":	"ȥ½�𴦴���ˮ�ʵ��¶�",
		"owner":	"lu yu",		
		"location":	"���Ƴ�",		
		"duration":		900,			
		"difficulty":	100,			
		"exp_l":		1000,						
		"exp_h":		2000,					
		"quest_type":	"special",		
	]),
		([	
		"quest":	"ɽ�亣ζ",
		"long":		"�������˵�����˴�Ĺ��ϰ�������ⲻ�ã�����ȥ������æô��",
		"short":	"ȥ������������û��ʲô�ɰ�æ��",
		"owner":	"haha er",		
		"location":	"���˴�",		
		"duration":		1800,			
		"difficulty":	200,			
		"exp_l":		1000,						
		"exp_h":		1500,					
		"quest_type":	"special",		
	]),
	([											// Ŀ�ģ�riddle
		"quest":		"����կ��ʵ",
		"long":			"���������ü�����ر�����կ��ͽ������ɽ���٣�������ȥ̽����ʵ�źã�
������˿��˿���˵��ƾ���������ӣ����»��������Ƕ��֣���ס��
�򲻹������ܡ�",
		"short":		"̽������կ��ʵ",
		"owner":		"none",				
		"location":		"�ر�",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		1500,				
		"exp_h":		2500,			
		"quest_type":	"special",		
	]),	
	([											// Ŀ�ģ�riddle
		"quest":		"˾��С��",
		"long":			"���������ü�������˴��С��ͻȻʧ���ˣ���ȥ��һ������ô���¶���",
		"short":		"�����˴��ҵ�С�̵�����",
		"owner":		"none",				
		"location":		"�ر�",	
		"cancel": 		-1,					
		"duration":		900,			
		"difficulty":	100,				
		"exp_l":		4000,				
		"exp_h":		5000,			
		"quest_type":	"special",		
	]),	
/*	([											// Ŀ�ģ�FY feature
		"quest":	"���ͻ���",
		"long":		"�������˵����ʨ�ھ�����ͷ�����������˻��ڣ����ȥ�����ɡ�",
		"short":	"���ʨ�ھֻ�һ����",
		"owner":	"meng",		
		"location":	"���Ƴ�",		
		"cancel": 		100,			
		"duration":		2700,			
		"difficulty":	400,			
		"exp_l":		1200,						
		"exp_h":		5000,					
		"quest_type":	"special",		
	]),*/		
		([											// Ŀ�ģ�riddle
		"quest":		"�����θ���",
		"long":			"���������ü�����߳��θ���Ļ����ֱ�����կ�ķ�ͽ���ˣ�
������˿��˿���˵����ѧ���гɣ�����ǿ������ȥ��ȥ���θ���",
		"short":		"��������կ�˻�",
		"owner":		"none",				
		"location":		"�ر�",				
		"duration":		1800,			
		"difficulty":	400,				
		"exp_l":		4500,				
		"exp_h":		5500,			
		"quest_type":	"special",		
	]),	
/*	([											// Ŀ�ģ�riddle
		"quest":		"��ϼɽ��",
		"long":			"���������ü�����Ƕ���ϼɽ��֮����Թ���Ƽ����Ϸ�ί���˺�ʦ̫ǰȥ���ȣ�
ֻ�޽��յ�·��������������������������Ϊ������ȥ̽��һ̽��ɽ��֮����������ʢ��
ֻ�»���ʲôа���������磬���Լ����С�ġ�",
		"short":		"���˺�ʦ̫��ѯ�ʳ���֮��",
		"owner":		"none",				
		"location":		"��ϼɽ",			
		"duration":		900,			
		"difficulty":	0,			
		"cancel": 		-1,				
		"exp_l":		5000,				
		"exp_h":		5200,			
		"quest_type":	"special",		
	]),	*/
	([
		"quest":	"��������",
		"long":		"�������˵���ţ����û��ʲô�¸��㣬�����죬��Ϣ��Ϣ�ɡ�",
		"short":	"���������Ӻ����������"YEL"�㱨"NOR,
		"owner":	"none",		
		"location":	"����ص�",		
		"cancel": -1,	// Cant cancel.
		"duration":		200,			
		"difficulty":	0,			
		"exp_l":		10,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),
});


mapping query_quest(int exp)
{
	int i, total;
	int *num = ({});
		
	total = sizeof(quest);
			
	for (i= 0; i< total; i++)	{
		if ( quest[i]["exp_l"] > exp ) continue;
		if ( quest[i]["exp_h"] < exp ) continue;
		num += ({ i });
	}
//	    CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",num) );	    
	
	if (!sizeof(num))    return 0;
		
	return quest[num[random(sizeof(num))]];
}
        
        
int TotalNumber()
{
	return sizeof(quest);
}
