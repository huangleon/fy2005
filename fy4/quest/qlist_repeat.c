/*	fy2005 introduces two new qlist
	Special Quest: qlist_special �� Repeatable Quest: qlist_repeat
	
	Qlist_repeat ��Ҫ��
	��0��Quest��ָ�������һ��NPC
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
	([
		"quest":	"�ͻ�",
		"long":		"�������˵��Ʈ�㻨����ϰ���ȱ�����ͻ�����ȥ�������æ�ɡ�",
		"short":	"��Ʈ�㻨����ϰ��ͻ�",
		"owner":	"huaman",		
		"location":	"Ʈ�㻨��",		
		"duration":		900,			
		"difficulty":	0,			
		"exp_l":		10,						
		"exp_h":		200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"�ͻ�",
		"long":		"�������˵�������򻨹���ȱ�����ͻ�����ȥ�������æ�ɡ�",
		"short":	"�������Ļ����ͻ�",
		"owner":	"huagu",		
		"location":	"������",		
		"duration":		900,			
		"difficulty":	0,			
		"exp_l":		15,						
		"exp_h":		200,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"���ͼ",
		"long":		"�������˵��������ֵ���������Ҫ���صķ������飬��ȥ������ʲô�������ġ�",
		"short":	"����������Ƹ��صĵ�ͼ",
		"owner":	"xu wanli",		
		"location":	"���Ƴ�",		
		"duration":	900,			
		"difficulty":	200,			
		"exp_l":		20,						
		"exp_h":		200,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"��̽ˮ��",
		"long":		"�������˵��ü��۵�½�ϰ���Ϊ���Ĳ�ˮ"YEL"ˮ��"CYN"�����ȥ�����ɡ�"NOR,
		"short":	"ȥ½�𴦴���ˮ�ʵ��¶�",
		"owner":	"lu yu",		
		"location":	"���Ƴ�",		
		"duration":		900,			
		"difficulty":	100,			
		"exp_l":		10,						
		"exp_h":		100,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"Ѱ��ʧ��",		// this quest "��ϼ����"
		"long":		"�������˵�����ŵ�����ǰ���Ӷ��˵㶫�������ȥ����"YEL"����"CYN"�ɡ�"NOR,
		"short":	"��������վѰ��ʧ��",
		"owner":	"officer wang",		
		"location":	"���Ƴ�",		
		"duration":		600,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		500,						
		"exp_h":		10000,							
		"quest_type":	"special",		
	]),
	([
		"quest":	"�һ��ִ���",		
		"long":		"�������˵����˵�䵱ɽ���������ũ���С����⡻��ȥ������ô���¶���",
		"short":	"ȥ�䵱��ũ���������",
		"owner":		"farmer",		
		"location":		"�䵱",		
		"duration":		401,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		200,						
		"exp_h":		350,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"�һ�������",		
		"long":		"�������˵����˵�䵱ɽ���������ũ���С����⡻��ȥ������ô���¶���",
		"short":	"ȥ�䵱��ũ���������",
		"owner":		"farmer",		
		"location":		"�䵱",		
		"duration":		402,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		350,						
		"exp_h":		500,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"�ͻ�",
		"long":		"�������˵��Ʈ�㻨����ϰ���ȱ�����ͻ�����ȥ�������æ�ɡ�",
		"short":	"��Ʈ�㻨����ϰ��ͻ�",
		"owner":	"huaman",		
		"location":	"Ʈ�㻨��",		
		"duration":		1200,			
		"cancel": 		100,
		"difficulty":	0,			
		"exp_l":		500,						
		"exp_h":		650,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"�ͻ�",
		"long":		"�������˵�������򻨹���ȱ�����ͻ�����ȥ�������æ�ɡ�",
		"short":	"�������Ļ����ͻ�",
		"owner":	"huagu",		
		"location":	"������",		
		"duration":		1200,
		"cancel": 		100,			
		"difficulty":	0,			
		"exp_l":		500,						
		"exp_h":		650,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"������̽��",		
		"long":		"����������ĵض���˵��ɽˮ����������ڡ����ˡ�����֪��ô��",
		"short":	"ȥ����㴦�������˵��¶�",
		"owner":		"zhong",		
		"location":		"���Ƴ�",		
		"duration":		411,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		600,						
		"exp_h":		750,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"������̽��",		
		"long":		"����������ĵض���˵��ɽˮ����������ڡ����ˡ�����֪��ô��",
		"short":	"ȥ����㴦�������˵��¶�",
		"owner":		"zhong",		
		"location":		"���Ƴ�",		
		"duration":		412,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		800,						
		"exp_h":		1000,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"ɱһ�����",		// this quest "��ϼ����"
		"long":		"�������˵���㲻��ȥ�����йݣ����������ʲô"YEL"����"NOR"��",
		"short":	"ȥ�����йݴ�������",
		"owner":	"princess",		
		"location":	"���Ƴ�",		
		"duration":	962,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 100,	// CC +100% 
		"exp_l":		900,						
		"exp_h":		1400,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"�������",		
		"long":		"�������˵�����幬����ʦ��Ϊ����֮�¡����ա�����ȥ��һ�ˣ�",
		"short":	"ȥ���˷紦�������յ��¶�",
		"owner":		"ding",		
		"location":		"���幬",		
		"duration":		421,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		1000,						
		"exp_h":		1200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"�������",		
		"long":		"�������˵�����幬����ʦ��Ϊ����֮�¡����ա�����ȥ��һ�ˣ�",
		"short":	"ȥ���˷紦�������յ��¶�",
		"owner":		"ding",		
		"location":		"���幬",		
		"duration":		422,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		1400,						
		"exp_h":		1800,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"ɱѩ������",		// this quest "��ϼ����"
		"long":		"�������˵���㲻��ȥ�����йݣ����������ʲô"YEL"����"NOR"��",
		"short":	"ȥ�����йݴ�������",
		"owner":	"princess",		
		"location":	"���Ƴ�",		
		"duration":	963,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 100,	// CC +100% 
		"exp_l":		1800,						
		"exp_h":		2400,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"����̽��",		
		"long":		"����������ĵض���˵��ɽˮ����������ڡ����ˡ�����֪��ô��",
		"short":	"ȥ����㴦�������˵��¶�",
		"owner":		"zhong",		
		"location":		"���Ƴ�",		
		"duration":		431,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		2300,						
		"exp_h":		2600,					
		"quest_type":	"special",		
	]),	
		([
		"quest":	"����̽��",		
		"long":		"����������ĵض���˵��ɽˮ����������ڡ����ˡ�����֪��ô��",
		"short":	"ȥ����㴦�������˵��¶�",
		"owner":		"zhong",		
		"location":		"���Ƴ�",		
		"duration":		432,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		2500,						
		"exp_h":		2800,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"ɱ��Ӱ��а",		// this quest "��ϼ����"
		"long":		"�������˵���㲻��ȥ�����йݣ����������ʲô"YEL"����"NOR"��",
		"short":	"ȥ�����йݴ�������",
		"owner":	"princess",		
		"location":	"���Ƴ�",		
		"duration":	964,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 100,	// CC +100% 
		"exp_l":		3200,						
		"exp_h":		3800,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"����̽��",		
		"long":		"����������ĵض���˵��ɽˮ����������ڡ����ˡ�����֪��ô��",
		"short":	"ȥ����㴦�������˵��¶�",
		"owner":		"zhong",		
		"location":		"���Ƴ�",		
		"duration":		433,	
		"difficulty":	100,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		3700,						
		"exp_h":		4200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"Ѫϴ����",		
		"long":		"�������˵���Ϲٽ������������ļ��,��ȥ���ܷ��ܡ�",
		"short":	"ȥ�Ϲٽ�������ļ���¶�",
		"owner":		"shangguan",		
		"location":		"���Ƴ�",		
		"duration":		441,	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		4300,						
		"exp_h":		4700,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"Ѫϴ����",		
		"long":		"�������˵���Ϲٽ������������ļ��,��ȥ���ܷ��ܡ�",
		"short":	"ȥ�Ϲٽ�������ļ���¶�",
		"owner":		"shangguan",		
		"location":		"���Ƴ�",		
		"duration":		442,	
		"difficulty":	50,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		4700,						
		"exp_h":		5200,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"��������",
		"long":		"�������˵���߳ǵ����ӽ���ϴ�֣��������ܳ���׷ɱ����ȥ������ɡ�",
		"short":	"ȥ�߳������Ӵ���һ����ʲô�ɰ�æ��",
		"owner":	"fatman",		
		"location":	"�߳�",		
		"duration":		1800,			
		"cancel": 200,	// CC +200% 
		"difficulty":	100,			
		"exp_l":		5000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"�������ׯ",
		"long":		"�������˵��̫ƽ�������ү�������˰�æ��ȥ��������ô���¶���",
		"short":	"ȥ̫ƽ��������ү����һ����ʲô�ɰ�æ��",
		"owner":	"sanye",		
		"location":	"̫ƽ��",		
		"duration":		1800,			
//		"cancel": 200,	// CC +200% 
		"difficulty":	200,			
		"exp_l":		6000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"̽�ô�����ɮ",
		"long":		"�������˵�����������������֯Ƶ������㲻��ȥ�ҳ�����ĺ��д���������",
		"short":	"ȥ�������Ҵ�����ɮ����������֯������",
		"owner":	"monk",		
		"location":	"������",		
		"duration":		1200,			
		"cancel": -1,	// CC +200% 
		"difficulty":	400,			
		"exp_l":		6000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"Ϲ��ƽ��",
		"long":		"�������˵�����ߵ�Ϲ��ƽ���������˰��֣���������Ҳ��֪����ɶ������ȥ����һ����",
		"short":	"����ϼɽ��Ϲ��ƽ�ߴ������",
		"owner":	"ping qi",		
		"location":	"��ϼɽ",		
		"duration":	600,
		"cancel": 200,	// CC +200% 
		"difficulty":	100,		// reward change in code
		"exp_l":		4000,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),	
	([
		"quest":	"��ĺ����",
		"long":		"�������˵��ȥ��ϼɽ����ĺ���˽�һ������Ĺ��£���Ϣ��Ϣ�ա�",
		"short":	"����ϼɽ����ĺ���˽�һ������Ĺ���",
		"owner":	"oldman",		
		"location":	"��ϼɽ",		
		"duration":	600,
//		"cancel": 	200,	// CC +200% 
		"difficulty":	440,			
		"exp_l":		3500,						
		"exp_h":		10000,					
		"quest_type":	"special",		
	]),

	([
		"quest":	"ɱɽ��֮��",		// this quest "�������"
		"long":		"�������˵���㲻��ȥ�����йݣ����������ʲô"YEL"����"NOR"��",
		"short":	"ȥ�����йݴ�������",
		"owner":	"princess",		
		"location":	"���Ƴ�",		
		"duration":		961,			// here we need a mark for the quest. you may change it later.	
		"difficulty":	0,		
		"cancel": 		100,	// CC +100% 
		"exp_l":		6500,						
		"exp_h":		8000,					
		"quest_type":	"special",		
	]),
	([
		"quest":	"�ջ�ļ���",
		"long":		"�������˵����Դ�Ĺ���������ƺ�����Ϊ������ȥ���Ϲ�ͷʹ����ȥ����������ʲôԭ��",
		"short":	"����Դ���������ķ���",
		"owner":	"guo dama",		
		"location":	"��Դ",		
		"duration":		900,			
		"cancel": 200,	// CC +200% 
		"difficulty":	200,			
		"exp_l":		3000,						
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