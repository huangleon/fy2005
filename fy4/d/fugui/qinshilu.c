inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
������һ����ʯС·�����ܵ��ƿ�����������ȥ�����̵����Ĳݺ������
С�ӡ�һ̧ͷ�����������Զ���ļ���С���ˡ���������ش���ԭ��������ΧС��
��ˮ��ӳ���£�Ҳ���м��ֽ���ˮ������ϡ�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"south":__DIR__"qinshilu3",
		"north":__DIR__"xiaojie4",
	]) );
	set("coor/x",20);
	set("coor/y",70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
