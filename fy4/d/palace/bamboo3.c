
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ѿ������ֵı�Ե��һ��СϪ��������Ծ�����������֣���һ�������֣�
СϪ�Ͱ�����������͸�����ֵķ�϶������Կ���һЩ�ߴ�ͦ�ε���������Լ�ɼ�
һЩ���߰�ǽ������¥��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"huding",
  "north" : __DIR__"bamboo2",
]));

        set("objects", ([
                __DIR__"npc/huatong" : 1,
                        ]) );
                        
        set("outdoors", "palace");
        set("resource/water",1);
         set("liquid/name","����Ϫˮ");
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

