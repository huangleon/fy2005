inherit ROOM;
void create()
{
        set("short", "̽��ʫ̨");
        set("long", @LONG
�����е��������ٴ�����ʫ�Դʵ��źá�ֻҪ������У��ͻ���ű�ī��������
���𣬵ȵ����է�������ǣ��ܱʼ��飬����ǧ�����䡣ʫ̨���������ľ��ݣ�
[33m
                       �����оƽ���
                       �Ĺ����ս���ͷ��
                                       ���������ھƺ�ʧ��ʱ��

[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud1",
]));
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
        set("coor/x",-10);
        set("coor/y",1);
        set("coor/z",-300);
        setup();
        call_other( "/obj/board/poem_b", "???" );
}
