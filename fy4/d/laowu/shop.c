
inherit ROOM;

void create()
{
        set("short", "��ҩ��");
        set("long", @LONG
�����ﲼ�õþ��Ŷ����£�ÿһ���������Ǿ�����ѡ�ģ����ð�����ǡ���ĵ�
����¯���յ���������Ҳ��ú��������������������ִ��ֺ����Ƥ����ů�þ���
�����������µĺ���һ����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"street1",
]));
        set("objects", ([
        __DIR__"npc/leng" : 1,
                        ]) );

	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

