inherit ROOM;
void create()
{
        set("short", "���ο����ǧ��");
        set("long", @LONG
���ο����ǧ��ʼ���ڹ�Ԫ���������ϸ߲���ʱ�ڣ�һֱ�Ǹ߲������ķ��
�صء��ڻ��󲿷ֲл٣��д沿�������Դ�����Ϊ�����С�������ʿ�䡱�����ٰ�
ͼ�����������䡱����С���ס��ȡ�
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"huoyan",
	]));
        set("objects", ([
        __DIR__"npc/youke" : 1,
        __DIR__"npc/ghost1" : 2,
                        ]) );
        //set("no_pk",1);
                
        set("outdoors", "xinjiang");
	set("coor/x",100);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
