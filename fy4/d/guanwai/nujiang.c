inherit ROOM;

void create()
{
      set("short", "ŭ��");

	set("long", @LONG
��ӿ����³�ز����������ˣ�����ͻȻ��խ����ˮŭ���İ���������ף��·�
һ���ݷ�ǧ��Ĳ������ڰ��β�ס������֮־�������ţ�ŭ���ţ������š�����һ
ȺҰ���������ڵ�����ɱ��š�
LONG);

         set("exits", ([ 
        "northwest" : __DIR__"tearoad2",
	]));
        set("outdoors", "guanwai");

	set("type","street");
        set("objects", ([
                __DIR__"npc/yema" : 1,
        ]) ); 
	set("coor/x",240);
	set("coor/y",-190);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
