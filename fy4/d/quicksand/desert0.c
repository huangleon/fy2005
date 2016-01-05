#include <ansi.h>

inherit __DIR__"quicksand.c";

void create()
{
	object san, sna;
	set("short", "��Į��ɳ");
	set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸�������������������ķ�
������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�·�ֻʣ��
��һ���ˡ�����»�����������ɳ�������ı����ĸо���
LONG
	);
	set("exits", ([ 
  		"west" : __DIR__"desert3",
  		"north" : __DIR__"desert1",
  		"south" : __DIR__"desert2",
  		"east"  : __DIR__"desert_entrance",
  		"down"  : __DIR__"quicksand0",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
		__DIR__"obj/teablock" : 1,
		__DIR__"obj/perfume" : 1,
		"obj/money/silver": 1,
        ]) );

	set("outdoors", "quicksand");
	set("coor/x",-1085);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	san = present("sand", this_object());
        sna = present("teablock", this_object());
        sna->move(san);
        sna = present("perfume", this_object());
        sna->move(san);
        sna = present("silver", this_object());
        sna->move(san);
}
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
		if( random(300)< 2)		  drop_him(ob);
	}
	else
	{
		if( random(1000)< 1)	drop_him(ob);
	}
	}
        add_action("do_pull", "pull");
}

int drop_him(object me)
{
	me->start_busy(1);
	call_out("dropnow", 1, me);
	return 1;

}
int dropnow(object me)
{
	if(environment(me) == this_object()){
        message_vision(HIW"$NͻȻ�е��ŵ�������ģ��޴�������", me);
        message_vision("$N���һ�������ã����������������ˡ�\n", me);
		message_vision("$N��������ɳ֮�У���\n"NOR, me); 
        me->move(__DIR__"quicksand0");
    }
        return 1;
}
	
int do_pull ( string arg)
{
	object me, who;
	object room;
	me = this_player();
        if ( !arg  ) return notify_fail("��Ҫ��˭������\n");
	room = load_object(__DIR__"quicksand0");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("��ɳ��û������ˡ�\n");
         message_vision(HIW"$N�þ�ȫ����������$n����ɳ�о��˳�����\n"NOR, me,who);
        who->move(__FILE__);
	return 1;

}
*/