

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "Цǳ¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

ֻҪ�а������м��ʡ�
Ҳ������˵�������Ƿ��ף����ǁ��У���Ȼ�Ƿ��ף��Ͳ��ü��ʡ���
˵��仰��������ʥ�ͣ�����α���ӡ�
ʥ�Ͳ�����α���Ӹ����Ͳ����һ��������������

LONG);
        set("exits", ([
  "down" : __DIR__"smile"+(query("floor")-1),
  "up" : __DIR__"smile"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
