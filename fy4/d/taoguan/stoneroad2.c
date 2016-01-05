// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
        set("short", "��ʯС��");
        set("long", @LONG
С����һ����һ��ľ������ߵ����ӡ��������ܵ��Ŵ��������Ĺ���, �ſ���
������һ����ɫ�����Ҷ�, ����[33m��̫��[32m�������֣���������һ��ʯ����С����
��ǰͨ��һ���ž���Ժ�䣬Ժ�Ű뿪�š�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast" : __DIR__"stoneroad",
            "north" : __DIR__"book_room1",
            "northwest": __DIR__"bieyuan",
	]));
        set("outdoors", "taoguan");
        set("item_desc", ([
            "bei" : "ʯ����д�� : \n\n"
                     "    ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n\nʯ���ϵ�һЩ��̦�б��˲����ĺۼ�����Ҳ������������ƿ���push����\n\n",
            "ʯ��" : "ʯ����д�� : \n\n"
                     "    ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n"
                     "    ��  ��\n\nʯ���ϵ�һЩ��̦�б��˲����ĺۼ�����Ҳ������������ƿ���push����\n\n"
           ]) );

	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}


void init()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
   	object me, room;
	int i,flag=0;
	string *msg = ({
"��","��","��","��","��","��","��","��","��",
});

   	me = this_player();


	if (!arg || (arg != "bei" && arg != "ʯ��"
		&& member_array(arg, msg) == -1 ))
		return notify_fail("��Ҫ��ʲô��\n");

	if (REWARD_D->riddle_check(me,"��������") != 5 
		&& !REWARD_D->check_m_success(me,"���ֻ�ɽ")) // ����������ʱ����������
		return notify_fail("
ʯ��ҡ��ҡ����������ƺ����˼��£���Ͻ��������۾���
ʯ������վ���������ض����㣬��Χ��������һƬ��\n");

	if (arg == "bei" || arg == "ʯ��") 
		return notify_fail("
ʯ��ҡ��ҡ����������ƺ����˼��£���Ͻ��������۾���
ʯ������վ���������ض����㣬��Χ��������һƬ��\n");

	for (i=0;i<9 ;i++ )
	{
		if (arg == msg[i])
		{
			if (query(("flag/"+(i+1))) == 1)
			{
				tell_object(me,"д�У�"+arg+"���ֵ�ʯ���Ѿ��ݽ�ȥ�ˡ�\n");
				return 1;
			}
/*			else
				tell_object(me,"д�У�"+query("flag/"+i+1)+"���ֵ�ʯ���Ѿ��ݽ�ȥ�ˡ�"+"flag/"+(i+1));
*/
			if (i != 1 && i != 3)
			{
				me->set_temp("annie/demon_taoguanstone",0);
			}
			else if (i == 1)
			{
				if (me->query_temp("annie/demon_taoguanstone") !=1)
					me->set_temp("annie/demon_taoguanstone",0);
				else
					me->set_temp("annie/demon_taoguanstone",2);
			}
			else if (i == 3)
			{
				if (me->query_temp("annie/demon_taoguanstone") !=0)
					me->set_temp("annie/demon_taoguanstone",0);
				else
					me->set_temp("annie/demon_taoguanstone",1);
			}
			message_vision(CYN"$N����֣���ʯ���ģ�"+arg+"����������һ�¡�\nд�У�"+arg+"���ֵ�ʯ�黺�������˽�ȥ��\n"NOR,me);
			flag = i+1;
		}
	}
	if (flag)
	{
		set("flag/"+flag,1);
		call_out("do_eject",2,me,flag);
		return 1;
	}
		return notify_fail("��Ҫ��ʲô��");
}


void do_eject(object me,int flag)
{
	string *msg = ({
"��","��","��","��","��","��","��","��","��",
});
	set("flag/"+flag,0);
	if (me->query_temp("annie/demon_taoguanstone") == 2 && environment(me) == this_object())
	{
		tell_object(me,CYN"ʯ����д�У������ֵ�ʯ�黺���Ļ��˳�����\n"NOR);
		tell_object(me,CYN"ʯ����д�У��ܣ��ֵ�ʯ�黺���Ļ��˳�����\n"NOR);
		me->set_temp("annie/demon_taoguanstone",0);
		message_vision(CYN"\nֻ����������һ�죬ʯ����Ȼ�������Ա߻������ߡ�\n"NOR,me);
		message_vision(CYN"$N���ֲ�����������ˤ����ȥ��\n"NOR,me);
		me->move(load_object(__DIR__"secretpath1"));
		if (me->query("kee") > 300)
			me->receive_wound("kee",300);
		else me->unconcious();
		message_vision(CYN"$N��žણ�һ������������\n"NOR,me);
		tell_room(this_object(),"ʯ�������Ļ���ԭλ���·�ʲôҲû�з�������\n");
		tell_room(this_object(),CYN"ʯ����д�У������ֵ�ʯ�黺���Ļ��˳�����\n"NOR);
		return;		
	}
	me->set_temp("annie/demon_taoguanstone",0);
	tell_room(this_object(),CYN"ʯ����д�У�"+msg[flag-1]+"���ֵ�ʯ�黺���Ļ��˳�����\n"NOR);
	return;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

