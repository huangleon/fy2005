#include <ansi.h>
#include <room.h>
#include <ansi.h>
inherit __DIR__"quicksand.c";


void create()
{
	object snake, ske, sand, too;
	set("short", "��Į��ɳ");
	set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸�������������������ķ�
������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�·�ֻʣ��
��һ���ˡ�����»�����������ɳ�������ı����ĸо���
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"desert7",
  "north" : __DIR__"desert6",
  "south" : __DIR__"desert3",
  "east"  : __DIR__"desert1",
  "down"  : __DIR__"quicksand5",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1060);
	set("coor/y",-20);
	set("coor/z",0);
	setup();

}

/*        ske = new(__DIR__"obj/skeleton");
        too = new(__DIR__"obj/budda-tooth");
        too->move(ske);
		snake = new(__DIR__"npc/snake");
        snake->move(ske);
        sand= present("sand", this_object());
        snake = new(__DIR__"npc/snake");
        snake->move(sand);
        ske->move(sand);*/


/*
void init()
{	object ob;
	object jade;
	int water, food, bellicosity;
	string outexit;
	if( interactive( ob = this_player()))
	{
	water = ob->query("water");
	food = ob->query("food");
	bellicosity = ob->query("bellicosity");
	water -= (random(4)+ 1) * water / 10;
	food -= (random(2)+ 1) * water / 10;
	bellicosity += random(10);
	ob->set("water", water);
	ob->set("food", food);
	ob->set("bellicosity", bellicosity);	
	if( !objectp(jade = present("jade", ob)))
	{
		if( random(50)< 2)		  drop_him(ob);
	}
	else
	{
		if( random(100)< 2)	drop_him(ob);
	}
	}
        add_action("do_pull", "pull");
        add_action("do_get","get");
}

int drop_him(object me)
{
        me->start_busy(1);
        call_out("dropnow", 1, me);
        return 1;

}

int dropnow(object me){
	if(environment(me) == this_object()){
        message_vision(HIW"$NͻȻ�е��ŵ�������ģ��޴�������", me);
        message_vision("$N���һ�������ã����������������ˡ�\n", me);
        message_vision("$N��������ɳ֮�У���\n"NOR, me);
        me->move(__DIR__"quicksand5");
    }
        return 1;
}
 
int do_pull ( string arg)
{
	object me, who;
	object room;
	me = this_player();
        if ( !arg  ) return notify_fail("��Ҫ��˭������\n");
	room = load_object(__DIR__"quicksand5");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("��ɳ��û������ˡ�\n");
         message_vision(HIW"$N�þ�ȫ����������$n����ɳ�о��˳�����\n"NOR, me,who);
        who->move(__FILE__);
	return 1;

}

int do_get(string arg)
{
	string what,where;
	if(!arg) return 0;
	if(sscanf(arg,"%s from %s",what,where) !=2) return 0;
	if((what== "skeleton" || what=="all") && where =="sand")
	{
		if (this_player()->is_busy())
			return notify_fail("��������æ��\n");
		if (this_player()->query("m_success/����",1) || this_player()->query("marks/get_tooth")
			|| this_player()->query_skill("iron-cloth",1)>=150)
		{
			message_vision(RED"��β��˻˻��������ͷ��$N������\n"NOR,this_player());
			message_vision("$N��æ�㬵������֡�\n",this_player());
			this_player()->start_busy(1);
			return 1;
		} else	{
			message_vision(RED"��β��˻˻��������ͷ��$N������\n"NOR,this_player());
			message_vision("$N������������ҧ�˸����š�\n",this_player());
			this_player()->receive_damage("kee",100);
			this_player()->set_temp("last_damage_from","����β�߶����ˡ�\n");
			tell_object(this_player(),HIR"С�ı�ҧ��������\n"NOR);
			return 0;
			}
	}
}
*/