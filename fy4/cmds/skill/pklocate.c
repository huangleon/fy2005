// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;

mapping area_name = ([ 
		"baiyun"	:	"���Ƴ�",
		"bat"		:	"����",
		"bashan"	: 	"��ɽ",
		"bawang"	:	"������",
		"biancheng"	:	"�߳�",
		"cave"		:   "���Ƶ��³�",
		"chenxiang"	:	"������",
		"chuenyu"	:	"���ɱ�",
		"cyan"		: 	"��ϼɽ",
		"daimiao"	:	"���",
		"death"		:	"���Ź�",
		"eastcoast"	: 	"����",
		"eren"		:    "���˹�",
		"eren2"		:    "���˹�",
		"fy"		:	"���Ƴ�",
		"fugui"		:    "����ɽׯ",
		"fycycle"	:  	"���Ƴ�",
		"fywall"	:   "���Ƴ�",
		"ghost"		:    "����ɽׯ",
		"guanwai"	:  	"����",
		"guanyin"	:  	"���",
		"huangshan"	:	"��ɽ",
		"huashan"	:  	"��ɽ",
		"jinan"		:    "����",
		"laowu"		:    "����",
		"libie"		:    "����С��",
		"loulan"	:   "¥��",
		"manglin"	:  	"ç��",
		"oldpine"	:  	"����կ",
		"palace"	:   "������",
		"qianfo"	:   "ǧ��ɽ",
		"qianjin"	:  	"ǧ��¥",
		"qingping"	: 	"��ƽɽׯ",
		"quicksand"	:	"��ɳĮ",
		"resort"	:   "��ѩɽׯ",
		"shaolin"	:  	"������",
		"shenshui"	: 	"��ˮ��",
		"songshan"	: 	"��ɽ",
		"taiping"	:  	"̫ƽ��",
		"taishan"	:  	"̩ɽ",
		"taoguan"	:  	"��Դ",
		"taoyuan"	:  	"�����",
		"tieflag"	:  	"�����",
		"wanmei"	:   "��÷ɽׯ",
		"wolfmount"	:	"��ɽ",
		"wudang"	:   "�䵱",
		"xiangsi"	: 	"��˼��",
		"xinjiang"	: 	"�½�",
		"yingou"	:   "�����ķ�",
		"zhaoze"	:	"�����",
		"zangbei"	:	"�ر�",
]);                             

int main(object me, string arg)
{                               
	object ob, man;
	int i, cost;            
	object room;            
	string location,*area,line;
                         
    if (me->query("NO_PK"))
		return notify_fail("������ֻ��Ѳ�����ӷ�����ʹ�á�\n");
	
	if ( !arg )             
		return notify_fail("��Ҫ���е���˭����Ϣ��\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("��Ҫ����˭����Ϣ��\n");
	if ( ob == me )         
		return notify_fail("�����۾������Լ��ɣ�\n");

	if (ob->query("NO_PK"))
		return notify_fail("������ֻ�����Ѳ�������ӷ�ʹ�á�\n");
		
    if ( present(ob, environment(me)) )
        return notify_fail("����˾�������ǰ��\n");

	if ( me->query("sen") <= 500 )
		return notify_fail("���������ٺķ�500������\n");
	me->receive_damage("sen", 500);		

	room=environment(ob);
	area=keys(area_name);
	if (!room) 
		write("���������������ҵ�"+ob->name()+"��\n");
	else {
		location=domain_file(file_name(room));
		if (member_array(location,area)==-1)	
			write("���������������ҵ�"+ob->name()+"��\n");
		else 
			write(ob->name()+"�������������"+area_name[location]+"һ���߶���\n");
			
	}
	me -> perform_busy(1);
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	pklocate <ĳ��>[0m
[0;1;37m����������������������������������������������������������������[0m   

������Ϊ���뽭����ɱ�����ר�ã����Դ���ȷ���������뽭����ɱ��
��ҵ����ڵ�����

[0;1;37m����������������������������������������������������������������[0m   

HELP
    );
    return 1;
}
