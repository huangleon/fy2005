inherit ROOM;
void create()
{
        set("short", "���Ʋ���");
        set("long", @LONG
�������������޳�У�����ר�Ŷ������ü�����װ����Ь��ñ��
�������������·�������ʽ��ӱ�����Ҿ������ã����������Ǵ��Ĵ�
���ݶ���������ģ��ſ���һ����ľ�ƣ�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud2",
]));
        set("objects", ([
        "/d/fy/npc/" : 1,
			]) );

        set("coor/x",20);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
