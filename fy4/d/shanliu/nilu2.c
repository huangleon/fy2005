// Room: nilu2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "����ɽ·");

	set("long", @LONG
����������·���ƺ����¹��꣬ɽ·Ҳ������Ţ���У����һ�Ÿ�һ����ǰŬ
�����ţ���һ������������������б��ˡ�ǰ�治Զ�ƺ��������ӣ��мҵ��̣���
��ǰ�ߣ�ɽ����������󣬵����������޷��������ǰ�Ķ����ˡ�
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"eastdown":__DIR__"nilu1",
	"westup":__DIR__"nilu3",
	]) );
	//}}
	set("coor/x",5);
	set("coor/y",10);
	set("coor/z",20);
		set("objects", ([
                __DIR__"npc/tianzong1" : 1,
                __DIR__"npc/tianzong2" : 1,
       ]) );

	setup();
	//replace_program(ROOM);
}
void init()
{
	object me;
	if (interactive(me=this_player()) && userp(me)
		 && (me->query_temp("��ɽ��/�Ͷ���") 
		 || (mapp(me->query("organization"))
		  && (string)me->query("organization/org_name")=="ɽ��")))
	{
		remove_call_out("killshanliu");
        call_out("killshanliu", 1, me);
	}
}
void killshanliu(object me)
{
	object acao,ashui;
	if( !me || environment(me) != this_object() ) return;
	acao = present("tianwu cao",this_object());
	if (!acao)
	{
		acao = new(__DIR__"npc/tianzong1");
		acao->move(this_object());
		message_vision("$N��ǰ��Ȼһ����һ����Ӱ��������ǰ��\n",me);
	}

	ashui = present("tianwu shui",this_object());
	if (!ashui)
	{
		ashui = new(__DIR__"npc/tianzong2");
		ashui->move(this_object());
		message_vision("$N��ǰ��Ȼһ����һ����Ӱ��������ǰ��\n",me);
	}
	message_vision("$N��$n����һЦ������ˮ˵���治�������Ȼ���˸�������\n",acao,me);
	acao->kill_ob(me);
	message_vision("$N������������֣�أ�ɽ�����˵�·�ߵ���������յ��ˡ�\n",ashui);
	ashui->kill_ob(me);
}

int valid_leave(object me, string dir)
{
	
	object assassinator;
	if (me->query_temp("��ɽ��/�Ͷ���"))
	{
		if ((assassinator = present("tianwu shui",this_object()) || assassinator= present("a cao",this_object())) && dir == "westup")
		{
			return notify_fail(assassinator->name()+"����бָ����סȥ·�������������ߣ���ɱ�����ǡ�\n");
		}
	}		

	if (random(6))
	{
		tell_object(me,"ɽ·Ҳ������Ţ���У����һ�Ÿ�һ����ǰŬ������\n");
		return notify_fail("");
	}			
	return 1;
}

