inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����Ľ������һ�񣬷����ر�ߣ��ɹ��Σ����滹�и��޴��ʮ�ּܡ�������
���������ĸ��񡣵����һЩ�𷢱��ۣ���������С��ʹ���������е�ʮ�ּ��϶�
��һ��ȫ����Ѫ���������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind2",
  "north" : __DIR__"chjian",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );
        set("valid_startroom",1);       // add by ldb ���������鱨���� 
        set("coor/x",10);
        set("coor/y",-20);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
