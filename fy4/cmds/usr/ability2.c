/*	ABILITY2
	mapping pfm_r1_data = ([
		"jichulianhuanjue":	([
			"e_id":	"jichulianhuan",
			"c_id":	"�Ƴ�����",
			"fixed_atk":	500,	// Enable = 500	
			"fixed_dmg":	640,	// str = 80
			"self_busy":	4,
			"cdt":			180,	// individual_cdt
			"g_cdt":		60,		// global_cdt
			"weapon":		1,
		]),
	]);

	������	pfm_r1_data[pfm_name[i]]["c_id"]
	Ӣ����	pfm_name[i]
	������	me->query("pfm_r1/"+pfm_name[i]+"/expertise");
	������	me->query("pfm_r1/"+pfm_name[i]+"/memorized");
		
	ʱ��	
	dur1 = ob->query("timer/pfm/pfm_r1") + r1_pfm_data[pfm_name[i]]["g_cdt"] -time();		// global timer
	dur2 = ob->query("timer/pfm/"+ pfm_name[i]) + r1_pfm_data[pfm_name[i]]["cdt"] -time();	// individual timer

	dur = dur1>dur2 ? dur1: dur2
	dur = dur>0: dur: 0;	


*/

#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *pfm_name = ({"tiandirenmojue","jichulianhuanjue","tianwaifeixianjue","luorijue","hantianjue","miwujue",
						"soulflamejue", "jixingjue", "jiemaijue", "mengyanjue" });
	mapping pfm_details = ([
		"tiandirenmojue":
"ȫ���������ħ�����˵���������ħ�������ƾ��߳�����ֶ�ʮ�ꡣ����һ
��ʩչ�����޾����ݣ�����������һ�����һ����

ʹ�ã�perform tiandirenmojue
˵��������æ�����֣�CDT300��\n",

		"jichulianhuanjue":
"����������˵�����л�ƹ����������շ������ƣ���Ϊ�˲�ʶ�����������
�콾Ҳ��Ȼ����һʱ�������꣬����һ����

ʹ�ã�perform jichulianhuanjue
˵��������æ�����֣�CDT300�룬���ܶԷ���ϬָӰ��\n",

		"tianwaifeixianjue":
"��Բ֮ҹ���Ͻ�֮�ߣ�һ��������������ɣ���Ϊ��һ�仰����֪�ж�����
���ڰ��Ƴ���Ҷ�³����¡�

ʹ�ã�perform tianwaifeixianjue
˵��������æ�����֣�CDT300�룬���ܶԷ����������\n",

		"luorijue":
"��������Բ��~��~~��~~~~��~~~~~��~~~~~~Բ��ֻ�м�������˧��һ�е��ˣ�
���������ɳĮ�е�׳����

ʹ�ã�perform luorijue
˵��������æ�����֣�CDT300�롣\n",

		"hantianjue":
"�����ڣ��˼��ǽ���ֻҪ���ڣ���������Ϊ�������Ŵ�ѩ�Ľ���������
�壬������һ��ʽ�еݳ���

ʹ�ã�perform hantianjue
˵��������æ��һ�֣�CDT300�롣\n",

		"miwujue":
"ʮ��������ɽ�续�������������������ڣ����񺯵��书ԶԶ�������µ�
һ�������������Ϊ���µ�һ���˽��˻�ɽ��®��û���ٻ��ų�����

ʹ�ã�perform miwujue
˵��������æ�Ҽ���CDT180�롣\n",

		"soulflamejue":
"��ħ�տޣ���ħҹ�ޣ���ħ��ޣ���ر�ɫ�����������ı��������еĲ���
�����������似�Ļ������޵�ħ����������ֻ�»���������ħ��֮�ϡ�

ʹ�ã�cast soulflamejue
˵����ͬʱ�������ж��ֵľ�������������æ��һ�֣�CDT180�롣\n",

		"jixingjue":
"ʩ���ǵ��䣬����⡢ҡ���â���Ͼ۾���֮�����¼�ʮ��֮���������䵱
������������۾���ǰߵ��������ҹ���ô��ڡ�

ʹ�ã�cast jixingjue
˵����������з�����ħ�����䷨�Ĺ�����������20�룬CDT180�롣\n",

		"jiemaijue":
"�����ϵ���������Ľ����������֡�ǰ�ߵ������ң�û��ɱ�����Ķ�ͽ��
���߿ɰ׹�������û�оȲ��صĲ��ˡ�

ʹ�ã�perform jiemaijue
˵����ս�������ƾ�������Ѫ����������ˣ�����æ��һ�֣�CDT300�롣\n",

		"mengyanjue":
"������������������������������һ����Ϊ����Զ�ȿ�ˡ����ȷ��ֱ
��������Ҷ������֪������ޱ������ʣ�ԭ��Ӧ�������ġ�

ʹ�ã�cast mengyanjue
˵�����ٻ�����֮��������ս��������20�룬CDT300�롣\n",

		]);
				
			
	string p_name,id,msg;
	int i,num, dur1, dur2, dur;
	object ob;
	
	if (wizardp(me))
	{
		if(arg && sscanf(arg, "-%s", id) == 1)
		{
			ob = present(id, environment(me));
			if (!ob) ob = find_player(id);
			if (!ob) ob = find_living(id);
			if (!ob) return notify_fail("��Ҫ�쿴˭�ķ��ƾ�����\n");			
		} else
			ob = me;					
	} else
		ob = me;
			
	if (arg && member_array(arg, pfm_name)!=-1) {
		
		if (ob->query("pfm_r1/"+arg+"/expertise")
				|| ob->query("pfm_r1/"+arg+"/memorized"))
		{
			write(HIG"\t����		"+pfm_r1_data[arg]["c_id"]+"\n"NOR);
			write(HIR BLK"������������������������������������������������������������������\n"NOR);
			write(pfm_details[arg]);
			write(HIR BLK"������������������������������������������������������������������\n"NOR);
			return 1;
		}
	}
		
	num = sizeof(pfm_name);
		
	write(HIG"\t����		���ƾ�������\n"NOR);
	write(HIR BLK"������������������������������������������������������������������\n"NOR);
	write(WHT    "���	������		Ӣ����		������	 ����	 ʱ��	\n"NOR);	
	write(HIR BLK"������������������������������������������������������������������\n"NOR);
	
	for(i=0; i<num; i++) {
		if (ob->query("pfm_r1/"+pfm_name[i]+"/expertise")
				|| ob->query("pfm_r1/"+pfm_name[i]+"/memorized"))
		{		
			dur1 = ob->query("timer/pfm/pfm_r1") + pfm_r1_data[pfm_name[i]]["g_cdt"] -time();		// global timer
			dur2 = ob->query("timer/pfm/"+ pfm_name[i]) + pfm_r1_data[pfm_name[i]]["cdt"] -time();	// individual timer
			dur = dur1>dur2 ? dur1: dur2;
			dur = dur>0? dur: 0;			
			msg = sprintf(WHT"%d"GRN"	%-12s"NOR" %-20s%d	��%d/3��	%3d	\n"NOR,
				i+1,
				pfm_r1_data[pfm_name[i]]["c_id"],
				pfm_name[i],
				ob->query("pfm_r1/"+pfm_name[i]+"/expertise"),
				ob->query("pfm_r1/"+pfm_name[i]+"/memorized"),
				dur,
				);
		} else
			msg = sprintf(WHT"%d\n"NOR,i+1);
		write(msg);
	}
				
	write(HIR BLK"������������������������������������������������������������������\n"NOR);


	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	ability2 [0m
[0;1;37m����������������������������������������������������������������[0m   

ability2 			���������յķ��ƾ���			
ability2 ����Ӣ����	���ڸþ��е�һЩ����˵��

�����ȣ�ÿʹ��һ�����������1�㣬һ��ʼ��Щ����Ҳ�������ۣ�����
�����ȵ���������������ߣ���������100������Ҫ��̿ھ���
	
���䣺������ǰֵΪ��ǰ����Ŀھ�����Ҳ���������ʹ�øþ��еĴ���
�����к�ְΪ��ͬʱ��������ھ���

ʱ�ޣ���һ��ʹ�øþ��еļ������ͬ�������Լ���ʱ�����ƣ���ͬ����
֮��ļ��Ϊ60�롣

ʹ�÷��ƾ�����ȼ�100���ϡ�

[0;1;37m����������������������������������������������������������������[0m  
HELP
    );

    return 1;
}
 
