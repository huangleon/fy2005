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
  "north" : __DIR__"beimen",
  "southeast" : __DIR__"bazha1",
  "southwest" : __DIR__"bazha2",
]));
        set("objects", ([
        __DIR__"npc/swaiter4" : 1,
        __DIR__"npc/swaiter5" : 1,
	__DIR__"npc/swaiter6" : 1,
	__DIR__"npc/swaiter11" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
