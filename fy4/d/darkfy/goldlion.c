inherit ROOM;
void create()
{
        set("short", "��ʨ�ھִ�Ժ");
        set("long", @LONG
�ھִ�Ժ���ʯ�̵أ���Ժ�ұ����ҵķ���һЩ��С������ʯ����������ھ�
�е������������������ġ����������ڴ�ϸһ�˶�ߵ�÷��׮����˵����ͷ����
ԭ���������׼ҵ��ӣ���ø���ָ�㣬���Ṧ���Ʒ��϶�����������衣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nwind4",
  "east"  : __DIR__"ghall", 
  "north" : __DIR__"gcang",
  "south" : __DIR__"gkitchen",
]));
        set("objects", ([
        __DIR__"npc/biaoshi" : 1,
        __DIR__"npc/biaoshi1": 1,
                        ]) );

        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
