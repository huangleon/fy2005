

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "Цǳ¥�ײ�");
  set ("long", @LONG

�����������������·�������ů���ǽ�
��������ָ���������ǳ��������ӯȱ
����������Ȼ��Ȼ�޾�ɫ��ζ��ǰ���Ժѩ
��������ѩ�������ѣ���Ӱ���ĺ�ʱ��

���������˳ַ�֦��������ЦԾ�����ﲻЪ
��������΢�۳�üæ�ƾͣ���Ⱦ��֬����ҹ
����������Ǻ���Ӧ����ҹ����������Ъ
��������Ī������������������������ͥ��

LONG);
        set("exits", ([
"107" : __DIR__"userroom/shi1397225953",
"106" : __DIR__"userroom/yun1396939345",
"105" : __DIR__"userroom/fls1396708171",
"104" : __DIR__"userroom/dao1396442292",
"103" : __DIR__"userroom/miao1396252753",
"102" : __DIR__"userroom/mlove1396189711",
"101" : __DIR__"userroom/mhua1395919554",
		  "up" : __DIR__"smile"+(query("floor")+1), 
  			"south" : __DIR__"enterance", 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",query("floor")*40);
	setup();
}
