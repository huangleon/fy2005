inherit ROOM;

void create()
{
	set("short", "ɽ��С·");

	set("long", @LONG
��������֪ͨ���δ���ɽ��С·��·�Ե�׺��Щ��ƣ���ף���죬���ϵ�
С����ɷ������ϲ������Զ����ɽ�����������ţ�ϯϯ���������Զ��С����
�˼Ҵ�����������㲻����Щ�����ꤣ���֪���δ����ٵ�Щ�óԵķ��ˡ�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"northeast":__DIR__"shanlu3",
		"northwest":__DIR__"shanlu5",
	]) );
	set("objects" , ([
		__DIR__"npc/beauty":1,
	]));
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	//replace_program(ROOM);
}
int invalid_leave(object me)
{
	if (me->query_temp("inrape"))
	{
		me->delete_temp("inrape");
	}
	return 0;
}
