inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������������������ľ���ս�����ֺ��η���ԼĪ���ɼ�����һ���ʯ�ݣ�
ǽ�ڶ���һ���ֲڵĴ�ʯ����������Ҳ�Ǵ�ʯ���̳ɣ��Ѿ��ܶ���û����ɨ��
���Ե��ϱ�ؾ������м���๸����ˮ��ǽ��һͷ����һֻ��Ͱ�������ŵ���
���ǳ�����ù����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"andao2",
]));
        set("objects", ([
        __DIR__"npc/jin9" : 1,
                        ]) );

	set("coor/x",70);
	set("coor/y",10);
	set("coor/z",-10);
	set("jinan_prison",1);
	set("no_fly",1);
	setup();
        
}
