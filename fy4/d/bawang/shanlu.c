inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
һ�����ѵ�����С�������Է賤��ЩҰ��Ұ���������ɽ����ɢ��������Ѫ��
��ζ��ɽ��ҲԽ��Խ�󣬰�ãã��һƬ������������ɽ��·����Լ��ɿ������Ϸ�
��Զ����һ��������
LONG);

	set("type","road");
	set("exits",([
        "northwest":"/d/wudang/xzroad4",
        "southup":__DIR__"shanlu2",

	]) );
	set("outdoors", "bawang");
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",-70);
	setup();
	replace_program(ROOM);
}
