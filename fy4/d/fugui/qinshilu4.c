inherit ROOM;

void create()
{
	set("short", "��ʯ·");

	set("long", @LONG
��������������ʯ��������Ծ���Щ��֪������ľ����;���ͻ��ƣ�ˮ������
������䣬��Ȼ�������Ͼ�ɫ�����ܲ�ľ������Σ������ƽ�����ĿԶ����Զ����
��������ֻ��ǰ�淿���۴��αȣ�ȴ�Ǹ�����·���и��ɰ���С�����ڽ�������
����
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"north":__DIR__"qinshilu2",
		"southwest":__DIR__"yidao5",
	]) );
        set("objects", ([
        	__DIR__"npc/tianxin" : 1,
		__DIR__"npc/farmer" : 1,
       	]) );
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
