// Silencer@fy4 workgroup

inherit ROOM;
#include <ansi.h>

int update_player(object me);

void create()
{
	set("short", HIG"���"NOR);
	set("long", @LONG
����һ̶����������أ�ԻΪ��أ���ˮ���ǳǳ���У��ݴ�����Ů洲�
�죬ɢ����Щ���߲���ʯ��׹���̶����Ϊ��ˮ��ÿһ��������Ƶ����˶�Ҫͽ��
�ʹ�������õ�һЩ������񣬶�һ�޶����컯��������[37m������[32m������
��������[1;32m���ǡ��������ٶȡ����ʡ�����������[0;32m�������ԡ�������ɽ�һ������
�����㵽�����������ԡ�����Ϊ[37m��������������[32m�������ϣ�������ԣ�
[37m�����������������塡��������[32m������ǣ�������һ����ǡ����Ե�˵
������[37m����𡡣�������[32m�еĲ�������ƪ��ѡ�������
LONG
	);
	set("exits", ([
  		"down" :  __DIR__"newbie5",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",800);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}



int init(){
	add_action("do_distribute", "distribute");
}


int valid_leave(object me, string dir) {

	if (dir == "down")
	if ( me->query("used_gift_points") != 10)
		return notify_fail("�����Ѳ����������ϡ�
�����������������塡�������飨����ǣ�\n");
	me->set_temp("first_time_login",1);
	return ::valid_leave(me, dir);
}

int do_distribute(string arg)
{
	int gift_points;
	int used_gift_points;
	object me;
	
	me = this_player();
	
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
			if((int) me->query("int") >=15)
				return notify_fail("��Ĳ��ǲ������÷���ķ���������ˡ�\n");
			me->add("used_gift_points",1);
			me->add("distribute/int",1);
			me->add("int",1);
			break;
        case "����" :
        case "tizhi" :
                        if((int) me->query("con") >=15)
                        	return notify_fail("������ʲ������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        me->add("distribute/con",1);
                        break;
        case "����" :
        case "yunqi" :
                        if((int) me->query("kar") >=15)
                        return notify_fail("��������������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        me->add("distribute/kar",1);
                        break;
        case "����" :
        case "liliang" :
                        if((int) me->query("str") >=15)
                        return notify_fail("��������������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        me->add("distribute/str",1);
                        break;
        case "�ٶ�" :
        case "sudu" :
                        if((int) me->query("agi") >=15)
                        return notify_fail("����ٶȲ������÷���ķ���������ˡ�\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        me->add("distribute/agi",1);
                        break;
        case "����" :
        case "dingli" :
                        if((int) me->query("cps") >=15)
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

int update_player(object me)
{
        object env, link_ob, obj;

        env = environment(me);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
        exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

	obj->receive_fulling("sen",500);
	obj->receive_fulling("gin",500);	// Leave kee out to do a demo downstairs
        obj->set("startroom", AREA_FY"fqkhotel");
        write ("���в����������ϣ����ﴴ����ϣ���ӭ����������硣\n");
        obj->move(env);
        obj->set_temp("first_time_login",1);
        obj->set_temp("successful_login", 1);
        obj->write_prompt();

        return 1;
}