inherit ROOM;
void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
˿��֮·������ǳ�������ʱ����˿���������Ʒ�����ڳ����Ժ󣬸�������
��һ��������˿��һƥƥ��У��������鲼��Ƥ��װ����Ȼ��ƺƵ���������̶ӣ�
�����¸ʸ�ԭ��Խ�������룬��������������������������ȣ�����ػ͡�һ����
�����ܲ����۵���·���ƺ�һ������ĺ��Ӷ����Խ�����ڽ��¡�������ǧ�����
ʷ�У�������ʳ�������˵������������ǵİ׹����ڵ�·���ԡ�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"sichou",
  "southeast" : __DIR__"sichou3",
]));
        set("objects", ([
	__DIR__"npc/trader2" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
