// Room: nongjia.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "é��");

	set("long", @LONG
�سǲ�ͷ����������˼�С�ݣ��������ڣ��Դ��������������һ��������
Ů�����ò���Ư������ȴ�������ᡣ���һ��û�л��������ͻἱ�ö㵽ϴ�·���
СϪ��ȥ͵͵���ᡣÿ������ס������ʱ������������������
LONG);

	set("type","indoors");
	set("exits",([
		"east":__DIR__"yard",
	]) );

        set("objects", ([
        ]) );
        set("indoors", "libie");
	set("coor/x",-7);
	set("coor/y",10);
	set("coor/z",0);

	setup();
}
