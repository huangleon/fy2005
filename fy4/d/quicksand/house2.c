
inherit ROOM;

void create()
{
        set("short", "���ҿ���");
        set("long", @LONG
�߹�ľҶɭɭ��Ժ�ӣ����ǿ��������Ŀ�������ǰ���ż������������յ���
���ȫ�����������⣬΢�紵�����������������������ڷ��衣�����Ĵ����
װ�ž������ɿڵĲˣ������ɵľƱ��ʢ��������ɫ�ľơ�
LONG
        );
        set("exits", ([ 
  		"out": __DIR__"house",
	]));
        set("objects", ([
        	__DIR__"npc/ji":	1,
                
        ]) );
	set("coor/x",-1035);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}

