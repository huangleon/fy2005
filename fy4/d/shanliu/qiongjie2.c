// Room: qiongjie2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "���");

	set("long", @LONG
�����������̸����ֶ�����Ҫüͷ���壬��Ϊ�����ֱ����ؤ�����ã�����
�Ĵ����ǳ���������󣬵���ֵ���ȴ������Щ�������ӳ��������Ȼ����Ǵ�
��������,����ɥ�����ߣ���Ϊ��Զ�������ڽ�����С��������"����Ӷķ�"��
��������������Ӷķ����ڴ�����ĵؽ���ά�ޣ��Ӹ�����������ľ���ϰѵ�·��
��ס�ˡ�
LONG);

	//{{ --- by MapMaker
	set("exits",([
	"southeast":__DIR__"qiongjie1",
	"southwest":__DIR__"qiongjie3",
	]) );
	//}}
        set("outdoors", "shanliu");
	set("coor/x",45);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object who, string dir){
	
	if (dir == "southwest"){
		return notify_fail("С���϶�������ľ���ϣ�һʱ���������߲���ȥ�ˡ�\n");
	}
	
	return ::valid_leave(who,dir);
}
