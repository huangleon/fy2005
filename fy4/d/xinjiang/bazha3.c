inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�������Ǽ��е���˼���������ġ����������ڶ���ǰ���ǡ�˿��֮·��������
���ĵط���ÿ��ϡ�������ʱ���������ز�Ʒ���ֹ���Ʒ���Ϲ��߲˵�һ���򡰰�
����ӿ������ʱ��ض����Կ���ͷ����ñ������Сë¿��������ʢװ���ˡ�
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"bazha1",
  "northwest" : __DIR__"bazha2",
  "south" : __DIR__"nanmen"
]));
        set("objects", ([
        __DIR__"npc/swaiter1" : 1,
	__DIR__"npc/swaiter2" : 1,
        __DIR__"npc/swaiter3" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
