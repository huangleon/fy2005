// Silencer@fy4 workgroup

// �������ã�����

// �����������㡢�������㣬����

// ���ػ����ļ��ܡ��鼮



inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"���Է��䷿��"NOR);
	set("long", @LONG
LONG
	);
	set("exits", ([
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	set("valid_startroom", 1);
	setup();
}

int init(){
	object me;
	string *att = ({"int","cps","agi","str","con","kar"});
	string *att_c = ({ "����","����","�ٶ�","����","����","����" });
	int i;
	
	// ���·������Ե�
	me = this_player();
	if (me->query("id") != "tester")	return 1;
	
	tell_object(me,"==========================================\n");
	for (i=0;i<sizeof(att);i++){
		tell_object(me,"������������"+ me->query("distribute/"+ att[i])+ "��"+ att_c[i]+"\n");		
	}
	
	tell_object(me,"\n���ڿ�ʼ���·������Ե㣬ԭ���Ķ��Ѿ����㡣\n\n");
	tell_object(me,"����Ϊ[37m��������������[32m�������ϣ�������ԣ�
[37m�����������������塡��������[32m������ǣ�
������һ����ǡ�\n");

	tell_object(me,"==========================================\n");
	
//	me->delete("distribute");
//	me->delete("used_gift_points");
	me->save();
	add_action("do_distribute","distribute");
		
}

int update_player(object me)
{
        object env, link_ob, obj;
        me->save();
        write ("���в����������ϣ��Զ�������һ�����䡣\n");
        obj->move(__DIR__"reset2");
        return 1;
}

int do_distribute(string arg)
{
	int gift_points;
	int used_gift_points;
	object me;
	
	me = this_player();
		
	me->set("update/fy51_attr_reset",1);
	
	if( !arg ) 
		return notify_fail("��Ҫ���䵽�ĸ������ϣ�
�����������������塡�������飨����ǣ�\n");
	gift_points = me->query("gift_points");
	used_gift_points = me->query("used_gift_points");
	if( used_gift_points >= gift_points )
		return notify_fail("��û�в�����ʣ���ˡ�\n");
	
	switch (arg) {
	case "����" :
	case "caizhi" :
			if((int) me->query("distribute/int") >=5)
				return notify_fail("��Ĳ��ǲ������÷���ķ���������ˡ�\n");
			me->add("used_gift_points",1);
			me->add("distribute/int",1);
			me->add("int",1);
			break;
        case "����" :
        case "tizhi" :
                        if((int) me->query("distribute/con") >=5)
                        	return notify_fail("������ʲ������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        me->add("distribute/con",1);
                        break;
        case "����" :
        case "yunqi" :
                        if((int) me->query("distribute/kar") >=5)
                        return notify_fail("��������������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        me->add("distribute/kar",1);
                        break;
        case "����" :
        case "liliang" :
                        if((int) me->query("distribute/str") >=5)
                        return notify_fail("��������������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        me->add("distribute/str",1);
                        break;
        case "�ٶ�" :
        case "sudu" :
                        if((int) me->query("distribute/agi") >=15)
                        return notify_fail("����ٶȲ������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        me->add("distribute/agi",1);
                        break;
        case "����" :
        case "dingli" :
                        if((int) me->query("distribute/cps") >=15)
                        return notify_fail("��Ķ����������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("cps",1);
                        me->add("distribute/cps",1);
                        break;
        default :
			return notify_fail("û�����������
�����������������塡�������飨����ǣ�\n");

	}
	write("���"+ arg + "�����һ�㡣\n");
	if ( used_gift_points < 9)
		write("�㻹��"+ chinese_number(gift_points - used_gift_points-1) + "���������������䡣\n");
	else 
		{
			update_player(me);
		}
	return 1;
}




	
	
	


