
inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
������ɻ���������һ��ɽɫ��Ǻ������������µĴ�����Ϊ������ʤ֮�ף�
������ɫ���컶��ˡ����ź���������������֦���ݣ�����������б�����գ�ӳ��
������졣��������ĺ�������ˮ���ɣ����ۺ��ϣ��ƺ����г��鷳�¶���һһ��
ȥ��̧����ȥ���̲�ƺ������������ˮ�����������Ƶ�ɽ����Լ�ɼ���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street2",
  "northeast" : __DIR__"road1",
  "southeast" : __DIR__"bridge1",
]));
        set("objects", ([
        __DIR__"npc/surong" : 1,
                        ]) );
        set("resource/water",1);
        set("liquid", ([
        "container":"������",
        "name":	"������ˮ",
        		]));
        	
    set("outdoors", "jinan");
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",0);
	setup();
}

/*
void init()
{
	string msg;
	msg = "asfsdfsa";
	message_vision(msg,this_player());
	message_vision(capitalize(msg),this_player());
}

*/
