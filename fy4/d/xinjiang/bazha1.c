inherit ROOM;
void create()
{
        set("short", "ľ���ᵱ��");
        set("long", @LONG
���������������ʮ�﷽ԲΨһ��һ�䵱�̣����ⲻ��Ҳ�����������������
�����ˣ��˺ܺã������Ͳ����ռ���˵ı��ˡ����̹����ƣ�����һ�顣
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"bazha",
  "west" : __DIR__"bazha2",
  "southwest" : __DIR__"bazha3",
]));
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

pawn        �䵱���
value       ���ۻ��
sell        ���ϻ��
redeem      ��ػ��

TEXT
        ]) );
        set("objects", ([
        __DIR__"npc/hockowner" : 1,
        __DIR__"npc/swaiter9" : 1,
        __DIR__"npc/swaiter10" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
