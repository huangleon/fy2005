inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ɰ����������ʮ��������ʯ���Ѿ��������䣬ԭ���ǹ�¥����ƽ����ס��
��Ϊʵ���ƾɣ���������Դ�������ѺһЩƽ���ķ��ˣ����ڰ������ң�Ҳû�д�
û�����Σ����������ıں�һЩɰ�����ֻ��������ŵ��������ˡ�
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"southstrt",
	]));
        set("objects", ([
                __DIR__"npc/wang" : 1,
                __DIR__"npc/zhu" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}
