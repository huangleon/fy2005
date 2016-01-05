#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�����");
    set("long", @LONG
���µĵ�ɢ������͵Ĺ⣬��ľ��̨����Χ���˼������ӡ���������Ĳ�����
��ô�ĺ�г��������볨��������飬ʹʹ���ؽ����е�ʵ��ʹ�ҷ�������
����Ϣ�ҡ�
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"hall",
//	"north" : __DIR__"courthouse",
	"east"  : __DIR__"jail",
	"down"  : AREA_FY"fysquare",
	"up"  : __DIR__"demoroom",
      ]));
    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",20);
    set("no_magic",1);
    set("no_fight",1);
    setup();
//    call_other("/obj/board/wizard_j", "???");

}

int valid_leave(object who, string dir){
	
	if (dir == "east")
		return notify_fail("���Ƽ��������ȥ����\n");

	if (dir == "up" && !wizardp(who))
		return notify_fail("����������������Ī�롣\n");
	
	if (dir == "south" && !wizardp(who))
		return notify_fail("�㲻�ܽ�����ʦ�İ칫�ҡ�\n");
	
	return ::valid_leave(who,dir);
}

int test3(){
	object ob;
	
	ob = find_living("silencer");
	write(sprintf("%O\n",ob));
	return 1;
}

int test4(){
	mapping x;
	x = ([ "a": 2, "b": 3, "c": 5 ]);
	map_delete(x,"a");
	write(sprintf("%O\n",x));
	return 1;
}
	
int test1(){

#ifdef NONENCRYPTED_WRITE

	object item;
	string *list,str,gender;
 	int i;
 	
	set("drop/common_drop",({
"/obj/generate/wrists_70_4.c",
"/obj/generate/surcoat_70_17.c",
"/obj/generate/neck_70_5.c",
"/obj/generate/neck_70_15.c",
"/obj/generate/head_70_15.c",
"/obj/generate/boots_70_16.c",
"/obj/generate/surcoat_70_5.c",
"/obj/generate/head_70_5.c",
"/obj/generate/cloth3_70_15.c",
"/obj/generate/cloth1_70_5.c",
"/obj/generate/boots_70_6.c",

	}) );
	
	set("drop/rare_drop",({
		"none",
	}) );
	
	list = query("drop/common_drop");
	for (i=0;i<sizeof(list);i++){
		item = new(list[i]);
		item->move(this_object());
		write((i+1)+": "+ item->query("name")+"("+list[i]+")  \n");
		
		gender = "����";
		if (item->query("male_only")) gender = "����";
		if (item->query("female_only")) gender = "Ů��";
			
		str = sprintf(YEL"(%s������ +%s ���� +%s ���� +%s ���� +%s �ٶ� +%s ������ +%d �� +%d �� +%d �� +%d )\n"NOR,
			gender,
			sprintf("%d.%d",item->query("armor_prop/intelligence")/10,item->query("armor_prop/intelligence")%10),
			sprintf("%d.%d",item->query("armor_prop/strength")/10,item->query("armor_prop/strength")%10),
			sprintf("%d.%d",item->query("armor_prop/composure")/10,item->query("armor_prop/composure")%10),
			sprintf("%d.%d",item->query("armor_prop/karma")/10,item->query("armor_prop/karma")%10),
			sprintf("%d.%d",item->query("armor_prop/agility")/10,item->query("armor_prop/agility")%10),
			item->query("armor_prop/armor"),
			item->query("armor_prop/max_gin"),
			item->query("armor_prop/max_kee"),
			item->query("armor_prop/max_sen"),
			);
			destruct(item);
		write(str);
	}
	
#endif
	return 1;
}


void test(){
	string msg;
	
	write(crypt("ս��",0));
	
	if (crypt("1972","Bj7mJPd4q6Pbk")== "Bj7mJPd4q6Pbk")
		write (" right \n");
	else
		write (" wrong\n");
	
}


void test2(string str){
	object ob,*ob1;
	int i;
	
	i = sizeof(users());
	
	write ("user = " + i + "\n");
}