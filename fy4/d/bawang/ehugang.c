#include <ansi.h>
inherit ROOM;
#define LOWER_LIMIT 150000
#define DUMP_PLACE  "/d/bawang/trap.c"

void create()
{
	set("short", "����������");

	set("long", @LONG
���ò�������γɸ���Ȼ��կ�ţ��������ɷ�������������֣�
					
                  �� �� �� 

������ƣ�Զɽ��䣬��˵���Ա����ƺ��������ڵ������п��µ����������
ȫ���Ҽ��ڶ����ڡ��������δ����Ŵ󿳵�����կ�š�  
LONG);

	set("type","road");
	set("exits",([
        "northdown":__DIR__"shanlu2",
		"southup":__DIR__"shanlu3",
	]) );

        set("objects", ([
        	__DIR__"npc/big_bandit": 1,
        	__DIR__"npc/lit_bandit": 1,
        ]));

	set("no_lu_letter",1);
	set("outdoors", "bawang");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	int wearing;
	object ob;
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if((string)inv[i]->query("name") == "�಼��"&& (int)inv[i]->query("equipped") )
		{
			wearing = 1;
		}
	}
	
	if(userp(me) && !me->query_temp("marks/keychain_ehg"))
	{
		if(dir == "southup" && ob=present("da louluo", this_object()))
		{
			if((string)me->name()!="��ɽ��" )
				return notify_fail("����������������������ȥȥȥ�����ǳԱ��˳ŵã��ܶ�����\n��תʲô�����Ķ����һ�������㣡\n");
			else if( !wearing)
			{
				return notify_fail("����޶������Ͽ������³�򣬴�������ð���������߾���Ϊ���������ˣ�\n");
			}
			else if( !me->query_temp("yuehu") )
			{
				return notify_fail("����������ʿ�ˮЦ������ɽ�����ָ�����կ�����ռ�����������ֻ��\n���ֵ��ǿɽ�������ȥ��......\n");
			}
			else
				return 1;		
		}
		else if (dir == "southup" && ob=present("xiao louluo", this_object()))
		{
			if((string)me->name()!="��ɽ��" )
				return notify_fail("С��������������������ȥȥȥ�����ǳԱ��˳ŵã��ܶ�����\n��תʲô�����Ķ����һ�������㣡\n");
			else if( !wearing)
			{
				return notify_fail("С��޶������Ͽ������³�򣬴�������ð���������߾���Ϊ���������ˣ�\n");
			}
			else if( !me->query_temp("yuehu") )
			{
				return notify_fail("С��������ʿ�ˮЦ������ɽ�����ָ�����կ�����ռ�����������ֻ��\n���ֵ��ǿɽ�������ȥ��......\n");
			}
			else
				return 1;		
		}
		return 1;
	}
	else 
		return 1;
}

void init() 
{ 
	add_action("do_kill", "kill"); 
}

int do_kill(string arg)
{ 
	object me;
	object room;
	object dalouluo, xiaolouluo;
	me = this_player();
	if(!arg) return 0;
	if( arg != "da louluo" && arg != "xiao louluo" && arg != "louluo") return 0;
	dalouluo = present("da louluo", this_object());
	xiaolouluo = present("xiao louluo", this_object());
	if(!objectp(dalouluo)) return 0;
	if(!objectp(xiaolouluo)) return 0;
	dalouluo->kill_ob(me);
	xiaolouluo->kill_ob(me);
	if( (int)me->query("combat_exp") <= LOWER_LIMIT)
	{
        	message_vision("С��޳���ɤ�Ӹߺ����е���Ӳ������������ѽ�� \n", me); 
		return 1;
	}
	else
	{
        	message_vision("С��޳���ɤ�ӽ����������ϣ�����ӹ�Ӳ���������......���ʹ���һ��......\n", me); 
        	message_vision("��С�����һè����������һ�������ֻ�������......\n",me);
        	message_vision(HIR "$NͻȻ���ֽ������գ������͵�һ������ǰ��ʱһ��......\n�����ϣ���ѽ����$N���һ����һ����������������ͨ��һ��������ȥ.......\n"NOR,me);
		room = find_object(DUMP_PLACE);
		if(!room) room=load_object(DUMP_PLACE);
		if(room)  me->move(room);
        	message("vision", me->name()+"������ֻˤ�����������磡����һ�����ʵʵ��ˤ�ڿӵס�\n", environment(me), me);
		return 1;
   }
}
