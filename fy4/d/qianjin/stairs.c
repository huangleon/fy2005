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
  "northdown" : __DIR__"tading",
  "northup" : __DIR__"stairs2",
]));

	set("coor/x",-65);
	set("coor/y",10);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
