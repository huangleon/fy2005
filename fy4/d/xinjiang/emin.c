inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ȫ��Ϊ������׿���������ֳ��չ���������������Ǭ¡��ʮ���꣬��һʽ�Ļ�
��ɫש���ɣ������Ͼ���������Բ�����Σ��´���ϸ��������ש����װ��������ơ�
ˮ���ơ������İ껨�ơ�ɽ�Ƶȼ���ͼ�ι�ʮ���֡��������ڲ�ͬ�߶Ⱥͷ��򿪳�
ʮ������ڡ����쾫�£���Ϊ׳�ۡ������ڲ��ṹ��û�л�ʯ��Ҳû��ľ�ϣ�����
ש������ʮ�༶���������������ȿɼӹ������ֿ������ʵ�ֱ��������
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"tulufan",
  "eastdown" : __DIR__"butao",
  "southeast" : __DIR__"gumu",
]));
        set("objects", ([
        __DIR__"npc/ghost" : 2,
        __DIR__"npc/ghost1" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
