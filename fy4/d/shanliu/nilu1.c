// Room: nilu1.c --- by MapMaker

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
	"westup":__DIR__"nilu2",
	"southeast":__DIR__"qiongjie4",
	]) );
	//}}
        set("outdoors", "shanliu");
	set("coor/x",12);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	
	if (random(4))
	{
		me->move(this_object());
		tell_object(me,"ɽ·Ҳ������Ţ���У����һ�Ÿ�һ����ǰŬ������\n");
		return notify_fail("");
	}		
	return 1;
}
