inherit ROOM;

void create()
{
	set("short", "��ھ�����");

	set("long", @LONG
������ã������������˴˴������Ȼ���ʣ��ѿ�վֱ�������㶨��һ�ƣ�
������ʧɫ�����л�Ȼ�����������ɣ�����ˮͰ�Ľ�ھ����������У�һ�Ա���
��棬˸Ȼ�Ź⡣���к��Ǳ�أ��ȳ��쳣���������
LONG);
    set("indoors", "fugui");
	set("type","mountain");
	set("exits",([
		"south":__DIR__"shandong",
	]) );
    	set("objects", ([
        	__DIR__"npc/bigsnake" : 1,
		__DIR__"obj/skeleton" : 2,
        ]) );

	set("coor/x",-10);
	set("coor/y",290);
	set("coor/z",80);
//	set("refresh_all_items", 1);
	setup();
}

