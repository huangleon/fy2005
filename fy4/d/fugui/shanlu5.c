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
		"southeast":__DIR__"shanlu4",
		"southwest":__DIR__"shanlu6",
	]) );
	set("coor/x",-30);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
