// Room: qiongjie5.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "���");

	set("long", @LONG
�����������̸����ֶ�����Ҫüͷ���壬��Ϊ�����ֱ����ؤ�����ã�����
�Ĵ����ǳ���������󣬵���ֵ���ȴ������Щ�������ӳ��������Ȼ����Ǵ�
��������������ɥ�����ߣ���Ϊ��Զ�������ڽ�����С��������"����Ӷķ�"��
��������û�в��뵽�����ģ�����û�������ķ羰��û�к��ûʵķ��ӣ���ȴ�к�
�ơ��òˡ��ÿ���Ů�ˡ���ƽ�ĶĲ���ʮ�������о������оŸ�ϲ��ȥ��
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"west":__DIR__"pomen",
	"northeast":__DIR__"qiongjie4",
	]) );
	//}}
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
