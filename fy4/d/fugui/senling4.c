inherit ROOM;

void create()
{
	set("short", "ɽ·");

	set("long", @LONG
��������᫵�ɽ·��·���Ӳݲ�����������������ʯ������·����ϡ���Կ���
����С����ĺ��ǣ�һ�ִ̱ǵĶ�����������̲�ס��ҪŻ�£��������٣�ǰ����
Ȼ���Ǹ���ڵ�ɽ�������˼���ѣ�ε�����ӭ��������
LONG);

	set("outdoors", "fugui");
	set("type","mountain");
	set("exits",([
		"south":__DIR__"senling3",
		"northeast":__DIR__"dongkou",
	]) );

	set("coor/x",-20);
	set("coor/y",260);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
