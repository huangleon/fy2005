inherit ROOM;
void create()
{
        set("short", "�ν����");
        set("long", @LONG
���ݿ�һ�ɣ�����̺�̿������ҷ�������������������ϡ�ϸ�����ݺ�̺��
��˿�ݺᣬ��Լ����һ�����꽻��ͼ������Ц֮����¥�ϴ�������ʱ��������һ
��������Ѫ�����ŵ��������㲻�������ļӿ��˲���������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"stairs",
  "southup" : __DIR__"secfloor",
]));

	set("coor/x",-65);
	set("coor/y",15);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
