inherit ROOM;
void create()
{
    set("short", "��Ǯ���Ժ");
    set("long", @LONG
��Ժ���������壬���ĳ��档Ժ�е������ڵ����ϳ�������Ӱ�ӡ�ż��������
�У������������ļž���΢�紵������Ҷ�趯��������ɳɳ������������ɳ�ĵ���
�����ݻƵ���Ҷ��������ɫ����Ӱ�������Ľ�����������֡�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"jindoor",
	"west" : __DIR__"jting",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",-160);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
