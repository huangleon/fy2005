inherit ROOM;

void create()
{
	set("short", "ɽ��С·");

	set("long", @LONG
��������֪ͨ���δ���ɽ��С·��·�Ե�׺��Щ��ƣ���ף���죬���ϵ�
С����ɷ������ϲ������Զ����ɽ�����������ţ�ϯϯ���������Զ��С����
�˼Ҵ�����������㲻����Щ�����ꤣ���֪���δ����ٵ�Щ�óԵķ��ˡ�·��
����������͸����������ܽǡ�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"northeast":__DIR__"shanlu5",
		"northwest":__DIR__"piaomiao",
	]) );
	set("coor/x",-40);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
